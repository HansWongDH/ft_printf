/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 03:48:40 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/15 10:54:52 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long long n, int radix)
{
	int	len;

	len = 0;
	if (n == 0)
		len += 1;
	while (n)
	{
		n /= radix;
		len++;
	}
	if (len < 0)
		return (0);
	return (len);
}

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

int	printhash(unsigned long long n, t_data data)
{
	int	count;

	count = 0;
	if (data.hash == 1 && n != 0)
	{
		if (data.flag == 'X')
			count += ft_putstr_print("0X");
		else
			count += ft_putstr_print("0x");
	}
	if (data.flag == 'p')
		count += ft_putstr_print("0x");
	return (count);
}

int	ft_print_hex(unsigned long long n, t_data data)
{
	char	*hex;
	int		count;
	int		iszero;

	count = 0;
	iszero = 0;
	if (data.flag == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n == 0 && data.dot == 1 && data.prec == 0)
		iszero = 1;
	comparewidthprec(n, 0, iszero, &data);
	if (iszero == 1)
		return (count += printwidth(data.width, data));
	if (!data.minus && data.width)
		count += printwidth(data.width, data);
	count += printhash(n, data);
	ft_puthex(n, &count, hex, &data);
	if (data.minus && data.width)
		count += printwidth(data.width, data);
	return (count);
}
