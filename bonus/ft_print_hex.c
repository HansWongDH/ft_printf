/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 03:48:40 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/13 22:09:23 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_puthex(unsigned long long nb, int *len, char *base, t_data *data)
{
	while (data->prec > 0)
	{
		*len += ft_putchar_print('0');
		data->prec--;
	}
	if (nb >= 16)
		ft_puthex(nb / 16, len, base, data);
	*len += ft_putchar_print(base[nb % 16]);
}

int	printHash(unsigned long long n, t_data data)
{
	int	count;

	count = 0;
	if (data.flag == 'p' || data.hash == 1)
	{
		if (n != 0)
		{
			if (data.flag == 'X')
				count += ft_putstr_print("0X");
			else
				count += ft_putstr_print("0x");
		}
		else if (data.flag == 'p')
			count += ft_putstr_print("(nil)");
	}
	return (count);
}

int	ft_print_hex(unsigned long long n, t_data data)
{
	char	*hex;
	int		count;

	count = 0;
	if (data.flag == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	compareWidthPrec(n, 0, &data);
	if (!data.minus && data.width)
		count += printWidth(data.width, data);
	count += printHash(n, data);
	ft_puthex(n, &count, hex, &data);
	if (data.minus && data.width)
		count += printWidth(data.width, data);
	return (count);
}
