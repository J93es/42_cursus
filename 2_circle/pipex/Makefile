NAME = pipex


M_DIR = ./src/
BONUS_DIR = ./src_bonus/


all : all_done
.PHONY : all


bonus : bonus_done
.PHONY : bonus


clean :
	make clean -C $(M_DIR)
	make clean -C $(BONUS_DIR)
	rm -rf 1_tester_pipex 2_tester_pipex
	rm -f all_done bonus_done
.PHONY : clean


fclean : 
	make fclean -C $(M_DIR)
	make fclean -C $(BONUS_DIR)
	make clean
	rm -f $(NAME)
.PHONY : fclean


re : 
	make fclean 
	make all
.PHONY : re


bonus_re :
	make fclean
	make bonus
.PHONY : bonus_re


test : 
	make re
	git clone git@github.com:vfurmane/pipex-tester.git 1_tester_pipex
	git clone git@github.com:denisgodoy/pipex-tester.git 2_tester_pipex
	cp $(NAME) ./2_tester_pipex/
.PHONY : test


test_bonus : 
	make bonus_re
	git clone git@github.com:vfurmane/pipex-tester.git 1_tester_pipex
	git clone git@github.com:denisgodoy/pipex-tester.git 2_tester_pipex
	cp $(NAME) ./2_tester_pipex/
.PHONY : test_bonus


all_done : 
	rm -f bonus_done
	make -C $(M_DIR)
	rm -f $(NAME)
	cp $(M_DIR)$(NAME) ./
	touch all_done


bonus_done : 
	rm -f all_done
	make -C $(BONUS_DIR)
	rm -f $(NAME)
	cp $(BONUS_DIR)$(NAME) ./
	touch bonus_done


$(NAME) : all_done

%.o : %.c
	$(CC) $(CFLAG) -c $^ -I$(INC_DIR) -o $@