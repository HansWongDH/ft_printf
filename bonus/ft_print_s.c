/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:41:13 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/13 20:32:47 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_strldup(const char *str, int len)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	checkSpace(t_data data)
{
	if (data.space)
		return (ft_putchar_print(' '));
	return (0);
}

int	printWidth(int len, t_data data)
{
	int	count;

	count = 0;
	if (data.space == 1 && len > 0)
		len -= 1;
	if (data.hash == 1 || data.flag == 'p')
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

int	printString(char *str, t_data data)
{
	int		len;
	int		count;
	char	*hold;

	count = 0;
	len = ft_strlen(str);
	count += checkSpace(data);
	if (len >= data.prec)
		len = data.prec;
	hold = ft_strldup(str, len);
	if (data.width > len && !data.minus)
		count += printWidth(data.width - len, data);
	count += ft_putstr_print(hold);
	if (data.width > len && data.minus)
		count += printWidth(data.width - len, data);
	free(hold);
	return (count);
}
