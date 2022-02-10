/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:51:25 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/10 18:06:08 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	int		tol;
	void	*ret;

	tol = num * size;
	ret = malloc(num * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero (ret, tol);
	return (ret);
}

int	ft_intlen(long n, int sign, int base)
{
	int	len;

	len = 0;
	if (sign < 0)
		len = 1;
	if (n == 0)
		len += 1;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*hold;
	long	num;

	num = (long)n;
	sign = 1;
	if (num < 0)
		sign *= -1;
	num *= sign;
	i = ft_intlen(num, sign, 10);
	hold = ft_calloc(i + 1, 1);
	if (!hold)
		return (NULL);
	if (sign < 0)
		hold[0] = '-';
	if (num == 0)
		hold[0] = '0';
	while (num)
	{
		hold[i-- - 1] = '0' + (num % 10);
		num /= 10;
	}
	return (hold);
}

char	*ft_itoa_hex(int n, char *hex)
{
	int		i;
	int		sign;
	char	*hold;
	long	num;

	sign = 1;
	num = (long)n;
	if (num < 0)
		num *= -1;
	i = ft_intlen(num, sign, 16);
	hold = ft_calloc(i + 1, 1);
	if (!hold)
		return (NULL);
	if (sign < 0)
		hold[0] = '-';
	if (num == 0)
		hold[0] = '0';
	while (num)
	{
		hold[i-- - 1] = hex[num % 16];
		num /= 16;
	}
	return (hold);
}

