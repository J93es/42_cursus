NAME = push_swap


CC = gcc
CFLAG = -Wall -Wextra -Werror #-fsanitize=address


INC_DIR = ./inc/
SRC_DIR = ./src/
CHECKERS_DIR = ./checkers/


SRC_NAME = push_swap.c \
	ft_preset.c \
	ft_sort.c \
	ft_search.c \
	ft_lst.c \
	ft_onlyn_sort.c \
	ft_action_px.c \
	ft_action_sx.c \
	ft_action_rx.c \
	ft_action_rrx.c \
	ft_utils.c


SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(SRC:%.c=%.o)
CHECKER = checker_MAC


all : $(NAME)
.PHONY : all


clean :
	rm -f $(OBJ) ./checker ./checker_MAC
	rm -rf 1_tester_push_swap 2_tester_push_swap
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
	git clone git@github.com:louisabricot/push_swap_tester.git 1_tester_push_swap
	git clone git@github.com:laisarena/push_swap_tester.git 2_tester_push_swap
	cp $(NAME) ./2_tester_push_swap/
.PHONY : test


$(NAME) : $(OBJ)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ)
	cp $(CHECKERS_DIR)$(CHECKER) ./checker


%.o : %.c
	$(CC) $(CFLAG) -c $^ -I$(INC_DIR) -o $@
