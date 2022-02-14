/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:49:18 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/15 07:08:21 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(long long n, int sign, int radix, int zero)
{
	int	len;

	len = 0;
	if (sign > 0 && !zero)
		len = 1;
	if (n == 0 && !zero)
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

void	ft_putprec(long nb, int *len, t_data *data)
{
	if (nb >= 0 && data->plus == 1)
	{
		*len += ft_putchar_print('+');
		data->plus = 0;
	}
	if (nb < 0)
	{
		*len += ft_putchar_print('-');
		nb *= -1;
		data->plus = 0;
	}
	while (data->prec > 0)
	{
		*len += ft_putchar_print('0');
		data->prec--;
	}
	if (nb >= 10)
		ft_putprec(nb / 10, len, data);
	*len += ft_putchar_print("0123456789"[nb % 10]);
}

int	checkSign(long n, t_data data)
{
	if (data.plus == 1 && n >= 0)
		return (1);
	if (n < 0)
		return (1);
	return (0);
}

int	ft_print_number(long n, t_data data)
{
	int	count;
	int	sign;
	int	iszero;

	count = 0;
	iszero = 0;
	sign = checkSign(n, data);
	if (sign == 0)
		count += checkSpace(data);
	if (n == 0 && data.dot == 1 && data.prec == 0)
		iszero = 1;
	compareWidthPrec(n, sign, iszero, &data);
	if (iszero == 1)
		return (count += printWidth(data.width, data));
	if (!data.minus && data.width)
		count += printWidth(data.width, data);
	ft_putprec(n, &count, &data);
	if (data.minus && data.width)
		count += printWidth(data.width, data);
	return (count);
}
