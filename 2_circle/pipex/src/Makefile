NAME = pipex


CC = gcc 
CFLAG = -Wall -Wextra -Werror #-g3 -fsanitize=address


SRC = pipex.c \
	ft_preset.c \
	ft_making.c \
	ft_making_utils.c \
	ft_str_utils1.c \
	ft_str_utils2.c \
	ft_make_pathname_opt.c \
	ft_split.c 


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