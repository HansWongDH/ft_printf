/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:34:31 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/15 05:20:46 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parseWidth(const char *str, int i, t_data *data)
{
	while (ft_isdigit(str[i]))
	{
		data->width = (data->width * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

int	printWidth(int len, t_data data)
{
	int	count;

	count = 0;
	if (data.space == 1 && len > 0 && ft_strchr("uid", data.flag))
		len -= 1;
	if (data.hash == 1 || (data.flag == 'p' && !data.null))
		len -= 2;
	while (len > 0)
	{
		if (data.zero)
			count += ft_putchar_print('0');
		else
			count += ft_putchar_print(' ');
		len--;
	}
	return (count);
}
