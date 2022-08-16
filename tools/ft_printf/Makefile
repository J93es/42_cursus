# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 21:13:00 by mijung            #+#    #+#              #
#    Updated: 2022/08/02 13:35:25 by mijung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf_lib.a

SRCS = ft_printf.c \
	ft_printf_utils.c

OBJS = $(SRCS:%.c=%.o)

AR = ar
ARFLAG = rcs

CC = cc
CFLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c $^ -I./ -o $@

clean :
	rm -f $(OBJS)

fclean : 
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
