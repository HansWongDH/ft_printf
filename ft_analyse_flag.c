/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 05:54:05 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/15 07:34:29 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	analyseFlag(const char *str, int i, t_data *data)
{
	while (str[i++])
	{
		if (!ft_isdigit(str[i]) && !ft_strchr("-. +#c%sxXuipd", str[i]))
			break ;
		if (str[i] == '+')
			data->plus = 1;
		if (str[i] == '#')
			data->hash = 1;
		if (str[i] == '-')
			data->minus = 1;
		if (str[i] == '0' && data->minus == 0 && data->dot == 0)
			data->zero = 1;
		if (ft_isdigit(str[i]) && !data->dot)
			i = parseWidth(str, i, data);
		if (str[i] == ' ')
			data->space = 1;
		if (str[i] == '.')
			i = parsePrecision(str, i + 1, data);
		if (ft_strchr("csx%Xuipd", str[i]))
		{
			data->flag = str[i];
			break ;
		}
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
		count += ft_putchar_char(va_arg(args, int), data);
	else if (data.flag == 's')
		count += ft_printString(va_arg(args, char *), data);
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
