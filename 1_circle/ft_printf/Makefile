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

NAME = libftprintf.a

SRC = ft_printf.c \
	ft_printf_utils.c

OBJ = $(SRC:%.c=%.o)

AR = ar
ARFLAG = rcs

CC = cc
CFLAG = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	make re -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_NAME) ./$(NAME)
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c $^ -I./ -o $@

clean :
	rm -f $(OBJ) $(LIBFT_NAME)
	make clean -C $(LIBFT_DIR)

fclean : 
	make clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re :
	make fclean
	make all

bonus :

.PHONY : all clean fclean re bonus
