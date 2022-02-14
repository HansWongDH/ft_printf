/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:40:55 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/15 07:19:49 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_char(char c, t_data data)
{
	int	count;

	count = 0;
	if (!data.minus && data.width > 1)
		count += printWidth(data.width - 1, data);
	count += ft_putchar_print(c);
	if (data.minus && data.width > 1)
		count += printWidth(data.width - 1, data);
	return (count);
}
