NAME = philo


CC = gcc
CFLAG =  -Wall -Wextra -Werror #-fsanitize=address


INC_DIR = ./inc/
SRC_DIR = ./src/


SRC_NAME = philo.c \
	ft_preset.c \
	ft_threading.c \
	ft_philo_cycle.c \
	ft_philo_utils.c


SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(SRC:%.c=%.o)


all : $(NAME)
.PHONY : all


clean :
	rm -f $(OBJ)
	rm -rf tester_philo
.PHONY : clean


fclean : 
	make clean
	rm -f $(NAME)
.PHONY : fclean


re : 
	make fclean
	make all
.PHONY : re


test : 
	make re
	git clone git@github.com:MichelleJiam/LazyPhilosophersTester.git tester_philo
.PHONY : test


$(NAME) : $(OBJ)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ)


%.o : %.c
	$(CC) $(CFLAG) -c $^ -I$(INC_DIR) -o $@
