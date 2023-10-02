NAME = mlx


ORG_MLX_TAR = minilibx_opengl.tar


ORG_MLX_MAKEFILE_DIR = mlx_makefile


all : $(NAME)
.PHONY : all
	

clean :
.PHONY : clean


fclean :
	rm -rf $(NAME)
.PHONY : fclean


re :
	make fclean
	make all
.PHONY : re


$(NAME) :
	tar xvf $(ORG_MLX_TAR)
	mv minilibx_opengl_20191021 $(NAME)
	rm $(NAME)/Makefile
	cp ./$(ORG_MLX_MAKEFILE_DIR)/Makefile $(NAME) 