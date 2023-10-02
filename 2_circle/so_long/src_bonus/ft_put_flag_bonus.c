#include "./so_long_bonus.h"

static void	ft_put_movecnt(t_tools *tools)
{
	char	*str;

	mlx_string_put(tools->mlx, tools->win, \
		tools->width * 64 - 46, 22, 0xFFFFFFFF, "move");
	mlx_string_put(tools->mlx, tools->win, \
		tools->width * 64 - 50, 33, 0xFFFFFFFF, "count");
	str = ft_itoa(tools->move_cnt);
	if (str == NULL)
		exit(ft_free(FTERROR, tools));
	if (tools->flag != FTFLAG_FIND && tools->flag != FTFLAG_WALL
		&& tools->flag != FTFLAG_USAGE)
		ft_printfd(1, "%s\n", str);
	mlx_string_put(tools->mlx, tools->win, \
		tools->width * 64 - 32 - 4 * ft_finddigit(tools->move_cnt), \
		50, 0xFFFFFFFF, str);
	free(str);
	str = NULL;
}

static void	ft_put_left_ring(t_tools *tools)
{	
	char	*str;

	mlx_string_put(tools->mlx, tools->win, 18, \
		tools->height * 64 - 44, 0xFFFFFFFF, "left");
	mlx_string_put(tools->mlx, tools->win, 18, \
		tools->height * 64 - 33, 0xFFFFFFFF, "blue");
	mlx_string_put(tools->mlx, tools->win, 18, \
		tools->height * 64 - 22, 0xFFFFFFFF, "ring");
	str = ft_itoa(tools->all_item - tools->item_cnt);
	if (str == NULL)
		exit(ft_free(FTERROR, tools));
	mlx_string_put(tools->mlx, tools->win, \
		32 - 4 * ft_finddigit(tools->all_item - tools->item_cnt), \
		tools->height * 64 - 8, 0xFFFFFFFF, str);
	free(str);
	str = NULL;
}

static void	ft_put_item_cnt(t_tools *tools)
{
	char	*str;

	mlx_string_put(tools->mlx, tools->win, \
		tools->width * 64 - 46, tools->height * 64 - 44, 0xFFFFFFFF, "blue");
	mlx_string_put(tools->mlx, tools->win, \
		tools->width * 64 - 46, tools->height * 64 - 33, 0xFFFFFFFF, "ring");
	mlx_string_put(tools->mlx, tools->win, \
		tools->width * 64 - 50, tools->height * 64 - 22, 0xFFFFFFFF, "count");
	str = ft_itoa(tools->item_cnt);
	if (str == NULL)
		exit(ft_free(FTERROR, tools));
	mlx_string_put(tools->mlx, tools->win, \
		tools->width * 64 - 32 - 4 * ft_finddigit(tools->item_cnt), \
		tools->height * 64 - 8, 0xFFFFFFFF, str);
	free(str);
	str = NULL;
}

void	ft_put_flag(t_tools *tools)
{
	ft_put_movecnt(tools);
	ft_put_item_cnt(tools);
	ft_put_left_ring(tools);
	if (tools->flag == FTFLAG_FIND)
		mlx_put_image_to_window(tools->mlx, tools->win, \
			tools->imgs.flag_find, 0, 0);
	if (tools->flag == FTFLAG_WALL)
		mlx_put_image_to_window(tools->mlx, tools->win, \
			tools->imgs.flag_wall, 0, 0);
	if (tools->flag == FTFLAG_USAGE)
		mlx_put_image_to_window(tools->mlx, tools->win, \
			tools->imgs.flag_usage, 0, 0);
	if (tools->flag == FTEXIT_WIN && ft_printfd(1, "YOU WIN!!\n") != 0)
		mlx_put_image_to_window(tools->mlx, tools->win, tools->imgs.win, 0, 0);
	if (tools->flag == FTEXIT_LOSE && ft_printfd(1, "YOU LOSE\n") != 0)
		mlx_put_image_to_window(tools->mlx, tools->win, tools->imgs.lose, 0, 0);
	if (tools->flag == FTEXIT_WIN || tools->flag == FTEXIT_LOSE)
		mlx_put_image_to_window(tools->mlx, tools->win, \
			tools->imgs.press_any_key, \
			tools->width * 64 / 2 - 64, tools->height * 64 / 2 - 64);
}
