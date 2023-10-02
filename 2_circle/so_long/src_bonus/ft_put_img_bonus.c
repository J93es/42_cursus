#include "./so_long_bonus.h"

static void	ft_put_img_sub(t_tools *tools, int i, int j)
{
	if (tools->all_item != tools->item_cnt)
	{
		if ((tools->map)[i][j] == 'P')
			mlx_put_image_to_window(tools->mlx, tools->win, \
				tools->imgs.p1, j * 64, i * 64);
		if ((tools->map)[i][j] == 'E')
			mlx_put_image_to_window(tools->mlx, tools->win, \
				tools->imgs.e1, j * 64, i * 64);
		if ((tools->map)[i][j] == '1')
			mlx_put_image_to_window(tools->mlx, tools->win, \
				tools->imgs.wall1, j * 64, i * 64);
	}
	else
	{
		if ((tools->map)[i][j] == 'P')
			mlx_put_image_to_window(tools->mlx, tools->win, \
				tools->imgs.p2, j * 64, i * 64);
		if ((tools->map)[i][j] == 'E')
			mlx_put_image_to_window(tools->mlx, tools->win, \
				tools->imgs.e2, j * 64, i * 64);
		if ((tools->map)[i][j] == '1')
			mlx_put_image_to_window(tools->mlx, tools->win, \
				tools->imgs.wall2, j * 64, i * 64);
	}
}

void	ft_put_img(t_tools *tools)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tools->height)
	{
		j = -1;
		while (++j < tools->width)
		{
			ft_put_img_sub(tools, i, j);
			if ((tools->map)[i][j] == 'C')
				mlx_put_image_to_window(tools->mlx, tools->win, \
					tools->imgs.c, j * 64, i * 64);
			if ((tools->map)[i][j] == '0')
				mlx_put_image_to_window(tools->mlx, tools->win, \
					tools->imgs.empty, j * 64, i * 64);
			if ((tools->map)[i][j] == 'B')
				mlx_put_image_to_window(tools->mlx, tools->win, \
					tools->imgs.ob, j * 64, i * 64);
			if ((i == 0 || i == tools->height - 1)
				&& (j == 0 || j == tools->width - 1))
				mlx_put_image_to_window(tools->mlx, tools->win, \
					tools->imgs.flag_empty, j * 64, i * 64);
		}
	}
}
