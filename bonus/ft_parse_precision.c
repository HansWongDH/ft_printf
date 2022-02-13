/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:02:27 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/13 20:04:15 by wding-ha         ###   ########.fr       */
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

int	parseWidth(const char *str, int i, t_data *data)
{
	while (ft_isdigit(str[i]))
	{
		data->width = (data->width * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}
