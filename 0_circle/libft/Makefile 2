# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 21:13:00 by mijung            #+#    #+#              #
#    Updated: 2022/07/11 21:13:14 by mijung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_A = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c

SRC_B = ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c

OBJ_A = $(SRC_A:%.c=%.o)
OBJ_B = $(SRC_B:%.c=%.o)

AR = ar
ARFLAG = rcs

CC = gcc
CFLAG = -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ = $(OBJ_A) $(OBJ_B)
else
	OBJ = $(OBJ_A)
endif

all : $(NAME)

bonus :
	make WITH_BONUS=1 all

$(NAME) : $(OBJ)
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c $^ -I ./ -o $@

clean :
	rm -f $(OBJ_A) $(OBJ_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
