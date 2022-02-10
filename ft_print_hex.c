/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 03:48:40 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/11 03:59:55 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long long nb, int *len, char *base)
{
	if (nb >= 16)
		ft_putptr(nb / 16, len, base);
	*len += ft_putchar_print(base[nb % 16]);
}

int	ft_print_hex(unsigned long long n, char flag)
{
	char	*hex;
	int		count;

	count = 0;
	if (flag == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (flag == 'p')
	{
		if (n != 0)
			count += ft_putstr_print("0x");
		else
		{
			count += ft_putstr_print("(nil)");
			return (count);
		}
	}
	ft_putptr(n, &count, hex);
	return (count);
}
