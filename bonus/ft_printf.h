/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:51:18 by wding-ha          #+#    #+#             */
/*   Updated: 2022/02/13 20:37:55 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

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

t_data	initStruct(void);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
int		ft_putchar_print(char c);
int		ft_putstr_print(char *str);
int		ft_print_number(long n, t_data data);
void	ft_putnbr(long nb, int *len, char *base);
void	ft_putprec(long nb, int *len, t_data *data);
int		analyseFlag(const char *str, int i, t_data *data);
int	parseWidth(const char *str, int i, t_data *data);
int	parsePrecision(const char *str, int i, t_data *data);
void	ft_putptr(unsigned long long nb, int *len, char *base);
int		ft_print_hex(unsigned long long n, t_data data);
int		ft_print_format(va_list args, t_data data);
int		ft_printf(const char *str, ...);
int		printString(char *str, t_data data);
char	*ft_strldup(const char *str, int len);
int	ft_intlen(long long n, int sign, int radix);
int	printWidth(int len, t_data data);
int	checkSpace(t_data data);
void	compareWidthPrec(long long n, int sign, t_data *data);

#endif 