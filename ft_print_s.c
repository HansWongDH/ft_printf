/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:41:13 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/15 07:32:46 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkSpace(t_data data)
{
	if (data.space)
		return (ft_putchar_print(' '));
	return (0);
}

int	ft_printString(char *str, t_data data)
{
	int		len;
	int		count;

	count = 0;
	if (!str)
	{
		if (data.dot == 1 && data.prec < 6)
			str = "";
		else
			str = "(null)";
	}
	len = ft_strlen(str);
	if (len >= data.prec && data.dot)
		len = data.prec;
	if (data.width > len && !data.minus)
		count += printWidth(data.width - len, data);
	count += ft_putstr_len(str, len);
	if (data.width > len && data.minus)
		count += printWidth(data.width - len, data);
	return (count);
}
