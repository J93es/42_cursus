NAME = pipex


CC = gcc 
CFLAG = -Wall -Wextra -Werror #-g3 -fsanitize=address


SRC = pipex_bonus.c \
	ft_preset_bonus.c \
	ft_making_bonus.c \
	ft_making_utils_bonus.c \
	ft_str_utils1_bonus.c \
	ft_str_utils2_bonus.c \
	ft_make_pathname_opt_bonus.c \
	ft_split_bonus.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c 
	

OBJ = $(SRC:%.c=%.o)


all : $(NAME)
.PHONY : all


clean :
	rm -f $(OBJ)
.PHONY : clean


fclean : 
	make clean
	rm -f $(NAME)
.PHONY : fclean


re : 
	make fclean 
	make all
.PHONY : re


$(NAME) : $(OBJ)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ)


%.o : %.c
	$(CC) $(CFLAG) -c $^ -I./ -o $@