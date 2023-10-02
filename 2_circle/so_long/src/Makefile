NAME = so_long


CC = gcc 
CFLAG = -Wall -Wextra -Werror #-g3 -fsanitize=address


MLX_DIR = ./mlx/
MLX_NAME = mlx
ORG_MLX_DIR = ./org_mlx/


SRC = so_long.c \
	ft_map_set.c \
	ft_img_set.c \
	ft_put_img.c \
	ft_put_flag.c \
	ft_str_utils1.c \
	ft_str_utils2.c \
	ft_split.c \
	get_next_line.c \
	get_next_line_utils.c 


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
