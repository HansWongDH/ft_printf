/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:37:04 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/14 22:48:52 by wding-ha         ###   ########.fr       */
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

int	ft_putstr_len(char *str, int len)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr_print("(null)"));
	while (str[i] && i < len)
		ft_putchar_print(str[i++]);
	return (i);
}
