/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:51:18 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/10 18:25:36 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
int		ft_intlen(long n, int sign, int base);
int		ft_putchar_print(char c);
int		ft_putstr_print(char *str);
int		ft_print_number(long n, char flag);
//int		ft_putnbr(int n, char *base, char flag, int radix);
void	ft_putnbr(long nb, int *len, char *base, int radix);
int		ft_print_hex(long n, char flag);
int		ft_print_format(va_list args, const char flag);
int		ft_printf(const char *str, ...);

#endif 