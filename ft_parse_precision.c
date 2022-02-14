/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:02:27 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/14 23:24:26 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	parsePrecision(const char *str, int i, t_data *data)
{
	data->dot = 1;
	while (ft_isdigit(str[i]))
	{
		data->prec = (data->prec * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

void	compareWidthPrec(long long n, int sign, t_data *data)
{
	int	radix;
	int	len;

	if (data->flag == 'x' || data->flag == 'X' || data->flag == 'p')
		radix = 16;
	else
		radix = 10;
	if (data->flag == 'p')
		len = ft_ptrlen(n, radix);
	else
		len = ft_intlen(n, sign, radix);
	if (data->prec > 0 && data->prec + sign >= len)
		data->prec = data->prec + sign - len;
	else
		data->prec = 0;
	if (data ->width <= data->prec + len)
		data->width = 0;
	if (data->width > 0 && data->width > data->prec + len)
		data->width = data->width - (data->prec + len);
	if (data->width && sign && data->zero)
	{
		data->prec += data->width;
		data->width = 0;
	}
}

