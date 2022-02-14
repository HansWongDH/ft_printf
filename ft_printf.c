/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:43:11 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/15 06:58:52 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	data.null = 0;
	return (data);
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
			i = analyseFlag(str, i, &data);
			len += ft_print_format(args, data);
			data = initStruct();
		}
		else
			len += ft_putchar_print(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
