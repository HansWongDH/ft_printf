/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:49:18 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/13 21:56:18 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
	if (nb < 0)
	{
		*len += ft_putchar_print('-');
		nb *= -1;
	}
	if (nb >= 0 && data->plus == 1)
	{
		*len += ft_putchar_print('+');
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
	/*if (data.hash == 1 && (data.flag == 'x' || data.flag == 'X'))
		return (2);
	if (data.flag == 'p')
		return (2);*/
	return (0);
}

void	compareWidthPrec(long long n, int sign, t_data *data)
{
	int	radix;
	int len;

	if (data->flag == 'x' || data->flag == 'X' || data->flag == 'p')
		radix = 16;
	else
		radix = 10;
	len = ft_intlen(n, sign, radix);
	if (data->prec > 0 && data->prec + sign > len)
		data->prec = data->prec + sign - len;
	if (data->width > 0 && data->width > data->prec + len)
		data->width = data->width - (data->prec + len);
	if (data ->width < data->prec + len)
		data->width = 0;
}

int	ft_print_number(long n, t_data data)
{
	int	count;
	int	sign;

	count = 0;
	sign = checkSign(n, data);
	count += checkSpace(data);
	compareWidthPrec(n, sign, &data);
	if (!data.minus && data.width)
		printWidth(data.width, data);
	ft_putprec(n, &count, &data);
	if (data.minus && data.width)
		printWidth(data.width, data);
	return (count);
}
