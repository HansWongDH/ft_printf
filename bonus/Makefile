# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 14:32:11 by wding-ha          #+#    #+#              #
#    Updated: 2022/02/13 22:23:22 by wding-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_printf_parse.c ft_printing.c ft_print_hex.c ft_parse_precision.c ft_print_num.c ft_print_s.c \
					./libft/ft_isdigit.c ./libft/ft_strchr.c ./libft/ft_strlen.c
OBJS			= $(SRCS:.c=.o)
LIBFT			= libft
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re