NAME = libmlx.a


CFLAGS += -O2
CFLAGS += -DSTRINGPUTX11


SRC = mlx_shaders.c \
	mlx_new_window.m \
	mlx_init_loop.m \
	mlx_new_image.m \
	mlx_xpm.c \
	mlx_int_str_to_wordtab.c \
	mlx_png.c \
	mlx_mouse.m


OBJ_TEMP = $(SRC:.c=.o)
OBJ = $(OBJ_TEMP:.m=.o)


all : $(NAME)
.PHONY : all


clean :
	rm -f $(OBJ) *~
	rm -rf mlx_app
.PHONY : clean


fclean :
	make clean
	rm -f $(NAME)
.PHONY : fclean


re: 
	make fclean
	make all
.PHONY : re


$(NAME) : $(OBJ)
	ar -r $(NAME) $(OBJ)
	ranlib $(NAME)
