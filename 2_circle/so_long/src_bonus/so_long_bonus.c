#include "./so_long_bonus.h"

static int	ft_ending(t_tools *tools)
{
	mlx_destroy_window(tools->mlx, tools->win);
	exit(ft_free(EXIT_SUCCESS, tools));
}

static int	ft_moving_sub(t_tools *tools, int i, int j)
{
	int	to_go;

	to_go = (tools->map)[(tools->p_index)[0] + i][(tools->p_index)[1] + j];
	(tools->move_cnt)++;
	if (to_go == 'E' && tools->all_item != tools->item_cnt
		&& --(tools->move_cnt) > -1)
		return (FTFLAG_FIND);
	if (to_go == '1' && --(tools->move_cnt) > -1)
		return (FTFLAG_WALL);
	if (to_go == 'C' && ++(tools->item_cnt) > -1)
		(tools->map)[(tools->p_index)[0]][(tools->p_index)[1]] = 'B';
	else
		(tools->map)[(tools->p_index)[0]][(tools->p_index)[1]] = '0';
	(tools->p_index)[0] += i;
	(tools->p_index)[1] += j;
	if (to_go == 'B')
		return (FTEXIT_LOSE);
	if (to_go == 'E' && tools->all_item == tools->item_cnt)
		return (FTEXIT_WIN);
	(tools->map)[(tools->p_index)[0]][(tools->p_index)[1]] = 'P';
	return (FTNORMAL);
}

static int	ft_moving(int key_num, t_tools *tools)
{
	if (tools->flag == FTEXIT_WIN || tools->flag == FTEXIT_LOSE
		|| key_num == FTKEY_ESC || key_num == 17)
		exit(0);
	if (key_num == FTKEY_W)
		tools->flag = ft_moving_sub(tools, -1, 0);
	else if (key_num == FTKEY_A)
		tools->flag = ft_moving_sub(tools, 0, -1);
	else if (key_num == FTKEY_S)
		tools->flag = ft_moving_sub(tools, 1, 0);
	else if (key_num == FTKEY_D)
		tools->flag = ft_moving_sub(tools, 0, 1);
	else
		tools->flag = FTFLAG_USAGE;
	ft_put_img(tools);
	ft_put_flag(tools);
	return (0);
}

int	ft_free(int return_num, t_tools *tools)
{
	int	i;

	i = -1;
	while (tools->map != NULL && (tools->map)[++i] != NULL)
	{
		free((tools->map)[i]);
		(tools->map)[1] = NULL;
	}
	if (tools->map != NULL)
	{
		free(tools->map);
		tools->map = NULL;
	}
	return (return_num);
}

int	main(int argc, char **argv)
{
	t_tools	tools;

	ft_map_set(argc, argv, &tools);
	tools.mlx = mlx_init();
	ft_img_set(&tools);
	tools.win = mlx_new_window(tools.mlx, \
		tools.width * 64, tools.height * 64, "so_long");
	ft_put_img(&tools);
	mlx_key_hook(tools.win, &ft_moving, &tools);
	mlx_hook(tools.win, 17, 0, &ft_ending, &tools);
	mlx_loop(tools.mlx);
	exit(ft_free(EXIT_SUCCESS, &tools));
}
