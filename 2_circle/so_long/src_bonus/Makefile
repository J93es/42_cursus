NAME = so_long


CC = gcc 
CFLAG = -Wall -Wextra -Werror #-g3 -fsanitize=address


MLX_DIR = ./mlx_bonus/
MLX_NAME = mlx_bonus
ORG_MLX_DIR = ./org_mlx_bonus/


SRC = so_long_bonus.c \
	ft_map_set_bonus.c \
	ft_img_set_bonus.c \
	ft_put_img_bonus.c \
	ft_put_flag_bonus.c \
	ft_str_utils1_bonus.c \
	ft_str_utils2_bonus.c \
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
	make fclean -C $(ORG_MLX_DIR)
	make clean
	rm -rf $(MLX_NAME)
	rm -f $(NAME)
.PHONY : fclean


re : 
	make fclean
	make all
.PHONY : re


$(NAME) : $(MLX_NAME) $(OBJ)
	arch -x86_64 $(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(MLX_DIR) -l$(MLX_NAME) -framework OpenGL -framework Appkit


$(MLX_NAME) :
	make all -C $(ORG_MLX_DIR)
	cp -r $(ORG_MLX_DIR)$(MLX_NAME) ./
	arch -x86_64 make all -C $(MLX_DIR)


%.o : %.c
	arch -x86_64 $(CC) $(CFLAG) -c $^ -I./ -o $@
