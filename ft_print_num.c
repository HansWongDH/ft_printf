/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:49:18 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/14 22:49:04 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(long long n, int sign, int radix)
{
	int	len;

	len = 0;
	if (sign > 0)
		len = 1;
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

	count = 0;
	sign = checkSign(n, data);
	if (sign == 0)
		count += checkSpace(data);
	compareWidthPrec(n, sign, &data);
	if (!data.minus && data.width)
		count += printWidth(data.width, data);
	ft_putprec(n, &count, &data);
	if (data.minus && data.width)
		count += printWidth(data.width, data);
	return (count);
}
