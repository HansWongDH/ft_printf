# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 14:32:11 by wding-ha          #+#    #+#              #
#    Updated: 2022/02/15 07:21:50 by wding-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_printf.c ft_analyse_flag.c ft_print_function.c ft_parse_precision.c ft_parse_width.c \
					ft_print_c.c ft_print_hex.c  ft_print_num.c ft_print_s.c	\

OBJS			= $(SRCS:.c=.o)
LIBFT			= libft
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C libft
				cp ./libft/libft.a ./$(NAME)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)
				make clean -C libft

fclean:			clean
				$(RM) $(NAME)
				make fclean -C libft

re:				fclean $(NAME)

bonus:			$(OBJS)
				make -C libft
				cp ./libft/libft.a ./$(NAME)
				ar rcs $(NAME) $(OBJS)

.PHONY:			all clean fclean re bonus