#include "./so_long.h"

static void	ft_img_src(t_tools *tools, int w, int h)
{
	tools->imgs.empty = \
		mlx_xpm_file_to_image(tools->mlx, "./img/src/empty.xpm", &w, &h);
	tools->imgs.ob = \
		mlx_xpm_file_to_image(tools->mlx, "./img/src/ob.xpm", &w, &h);
	tools->imgs.c = \
		mlx_xpm_file_to_image(tools->mlx, "./img/src/item.xpm", &w, &h);
	tools->imgs.p1 = \
		mlx_xpm_file_to_image(tools->mlx, "./img/src/player1.xpm", &w, &h);
	tools->imgs.e1 = \
		mlx_xpm_file_to_image(tools->mlx, "./img/src/exit1.xpm", &w, &h);
	tools->imgs.wall1 = \
		mlx_xpm_file_to_image(tools->mlx, "./img/src/wall1.xpm", &w, &h);
	tools->imgs.p2 = \
		mlx_xpm_file_to_image(tools->mlx, "./img/src/player2.xpm", &w, &h);
	tools->imgs.e2 = \
		mlx_xpm_file_to_image(tools->mlx, "./img/src/exit2.xpm", &w, &h);
	tools->imgs.wall2 = \
		mlx_xpm_file_to_image(tools->mlx, "./img/src/wall2.xpm", &w, &h);
}

static void	ft_img_flag(t_tools *tools, int w, int h)
{
	tools->imgs.flag_empty = \
		mlx_xpm_file_to_image(tools->mlx, "./img/flag/flag_empty.xpm", &w, &h);
	tools->imgs.flag_find = \
		mlx_xpm_file_to_image(tools->mlx, "./img/flag/flag_find.xpm", &w, &h);
	tools->imgs.flag_wall = \
		mlx_xpm_file_to_image(tools->mlx, "./img/flag/flag_wall.xpm", &w, &h);
	tools->imgs.flag_usage = \
		mlx_xpm_file_to_image(tools->mlx, "./img/flag/flag_usage.xpm", &w, &h);
	tools->imgs.win = \
		mlx_xpm_file_to_image(tools->mlx, "./img/flag/exit_win.xpm", &w, &h);
	tools->imgs.lose = \
		mlx_xpm_file_to_image(tools->mlx, "./img/flag/exit_lose.xpm", &w, &h);
	tools->imgs.press_any_key = \
		mlx_xpm_file_to_image(tools->mlx, \
			"./img/flag/press_any_key.xpm", &w, &h);
}

void	ft_img_set(t_tools *tools)
{
	ft_img_src(tools, 0, 0);
	ft_img_flag(tools, 0, 0);
}
