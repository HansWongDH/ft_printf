/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:51:18 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/15 10:55:33 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_data
{
	int			flag;
	int			width;
	int			dot;
	int			minus;
	int			zero;
	int			prec;
	int			hash;
	int			space;
	int			plus;
}				t_data;

t_data	initstruct(void);
int		ft_printf(const char *str, ...);
int		checkspace(t_data data);
int		ft_printstring(char *str, t_data data);
int		ft_intlen(long long n, int sign, int radix, int zero);
void	ft_putprec(long nb, int *len, t_data *data);
int		checksign(long n, t_data data);
int		ft_print_number(long n, t_data data);
int		ft_ptrlen(unsigned long long n, int radix);
void	ft_puthex(unsigned long long nb, int *len, char *base, t_data *data);
int		printhash(unsigned long long n, t_data data);
int		ft_print_hex(unsigned long long n, t_data data);
int		ft_putchar_print(char c);
int		ft_putstr_print(char *str);
int		ft_putstr_len(char *str, int len);
int		ft_putchar_char(char c, t_data data);
int		parsewidth(const char *str, int i, t_data *data);
int		printwidth(int len, t_data data);
int		parseprecision(const char *str, int i, t_data *data);
void	comparewidthprec(long long n, int sign, int iszero, t_data *data);
int		analyseflag(const char *str, int i, t_data *data);
int		ft_print_format(va_list args, t_data data);

#endif 