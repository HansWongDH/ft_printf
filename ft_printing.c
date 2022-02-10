/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:37:04 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/10 18:29:45 by wding-ha         ###   ########.fr       */
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

int	ft_print_number(long n, char flag)
{
	int		i;

	i = 0;
	if (flag == 'u' && n < 0)
		n *= -1;
	ft_putnbr(n, &i, "0123456789", 10);
	return (i);
}

void	ft_putnbr(long nb, int *len, char *base, int radix)
{
	if (nb < 0)
	{
		*len += ft_putchar_print('-');
		ft_putnbr(-nb, len, base, radix);
		return ;
	}
	if (nb > radix - 1)
	{
		ft_putnbr(nb / radix, len, base, radix);
		return ;
	}
	*len += ft_putchar_print(base[nb % radix]);
}

int	ft_print_hex(long n, char flag)
{
	char	*hex;
	int		count;

	count = 0;
	n = 0;
	if (flag == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (flag == 'p')
		count += ft_putstr_print("0x");
	ft_putnbr(n, &count, hex, 16);
	return (count);
}
