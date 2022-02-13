/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:37:04 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/12 03:25:42 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_print(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_print(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr_print("(null)"));
	while (str[i])
		ft_putchar_print(str[i++]);
	return (i);
}

void	ft_putnbr(long nb, int *len, char *base)
{
	if (nb < 0)
	{
		*len += ft_putchar_print('-');
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, len, base);
	*len += ft_putchar_print(base[nb % 10]);
}
