#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 18:19:24 by vkozhemi          #+#    #+#              #
#    Updated: 2018/08/01 13:10:37 by vkozhemi         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
TEST = ft_printf.out
SRCS = printf.c conversions.c parsing.c ft_wchar_c.c int.c str_c_pointer_wchars.c uns_int.c \
		int_flag_no_minus.c int_flag_minus.c uns_int_flag_minus.c uns_int_flag_no_minus.c \
		ft_char.c ft_str.c ft_pointer.c ft_percent.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME):
	@gcc -c -g -Wall -Wextra -Werror libft/*.c -I libft/libft.h
	@gcc -c $(SRCS)
	@ar rc $(NAME) *.o

test:
	@gcc -g -L. -lftprintf $(SRCS) ../printf1/main.c -o $(TEST)

clean:
	@rm -rf *.o libft/*.o

fclean: clean
	@rm -rf $(NAME) libft/*.a

re: fclean all