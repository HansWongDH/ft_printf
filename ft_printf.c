/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:51:13 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/10 17:34:12 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(va_list args, const char flag)
{
	int	count;

	count = 0;
	if (flag == '%')
		count += ft_putchar_print('%');
	else if (flag == 'c')
		count += ft_putchar_print(va_arg(args, int));
	else if (flag == 's')
		count += ft_putstr_print(va_arg(args, char *));
	else if (flag == 'x' || flag == 'X')
		count += ft_print_hex(va_arg(args, int), flag);
	else if (flag == 'p')
		count += ft_print_hex(va_arg(args, int), flag);
	else if (flag == 'd' || flag == 'i')
		count += ft_print_number(va_arg(args, int), flag);
	else if (flag == 'u')
		count += ft_print_number(va_arg(args, unsigned int), flag);
	else
		return (0);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_print_format(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar_print(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
