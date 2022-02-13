/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 05:54:05 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/13 20:04:05 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_data	initStruct(void)
{
	t_data	data;

	data.flag = 0;
	data.width = 0;
	data.dot = 0;
	data.minus = 0;
	data.zero = 0;
	data.prec = 0;
	data.hash = 0;
	data.space = 0;
	data.plus = 0;
	return (data);
}

int	analyseFlag(const char *str, int i, t_data *data)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_strchr("-. +#csxXuipd", str[i]))
			break ;
		if (ft_isdigit(str[i]) && !data->dot)
			i = parseWidth(str, i, data);
		if (str[i] == '+')
			data->plus = 1;
		if (str[i] == '#')
			data->hash = 1;
		if (str[i] == '-')
			data->minus = 1;
		if (str[i] == '0' && data->minus == 0)
			data->zero = 1;
		if (str[i] == ' ')
			data->space = 1;
		if (str[i] == '.')
			i = parsePrecision(str, i + 1, data);
		if (ft_strchr("csxXuipd", str[i]))
		{
			data->flag = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_print_format(va_list args, t_data data)
{
	int	count;

	count = 0;
	if (data.flag == '%')
		count += ft_putchar_print('%');
	else if (data.flag == 'c')
		count += ft_putchar_print(va_arg(args, int));
	else if (data.flag == 's')
		count += printString(va_arg(args, char *), data);
	else if (data.flag == 'x' || data.flag == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), data);
	else if (data.flag == 'p')
		count += ft_print_hex(va_arg(args, unsigned long long), data);
	else if (data.flag == 'd' || data.flag == 'i')
		count += ft_print_number(va_arg(args, int), data);
	else if (data.flag == 'u')
		count += ft_print_number(va_arg(args, unsigned int), data);
	else
		return (0);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	t_data	data;

	i = 0;
	len = 0;
	data = initStruct();
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = analyseFlag(str, i + 1, &data);
			len += ft_print_format(args, data);
		}
		else
			len += ft_putchar_print(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
