#include "../inc/push_swap.h"

static void	ft_set_len(int argc, char **argv, t_tools *tools)
{
	tools->y = 0;
	tools->len = 0;
	while (++(tools->y) < argc)
	{
		tools->x = 0;
		while (argv[tools->y][tools->x] != 0)
		{
			while (ft_iswhat(argv[tools->y][tools->x], 0) == FTSPACE)
				(tools->x)++;
			if (argv[tools->y][tools->x] == '+'
				|| argv[tools->y][tools->x] == '-')
				(tools->x)++;
			while (ft_iswhat(argv[tools->y][tools->x], 0) == FTDIGIT)
				(tools->x)++;
			if ((tools->x > 0
					&& ft_iswhat(argv[tools->y][tools->x - 1], 0) == FTFALSE)
				|| (argv[tools->y][tools->x] != 0
					&& ft_iswhat(argv[tools->y][tools->x], 0) == FTFALSE))
				exit(ft_free(tools, FTERROR));
			if (tools->x > 0
				&& ft_iswhat(argv[tools->y][tools->x - 1], 0) == FTDIGIT)
				(tools->len)++;
		}
	}
}

static void	ft_set_malloc(t_tools *tools)
{
	long	i;

	tools->a_st = malloc(sizeof (long) * (tools->len + 4));
	tools->b_st = malloc(sizeof (long) * (tools->len + 4));
	tools->answer = malloc(sizeof (long) * tools->len);
	if (tools->a_st == 0 || tools->b_st == 0 || tools->answer == 0)
		exit(ft_free(tools, FTMERROR));
	tools->a_top = 1;
	tools->a_down = tools->len + 2;
	(tools->a_st)[0] = ST_HEAD_NBR;
	(tools->a_st)[1] = ST_TOP_NBR;
	(tools->a_st)[tools->len + 2] = ST_DOWN_NBR;
	(tools->a_st)[tools->len + 3] = ST_TAIL_NBR;
	tools->a_len = tools->len;
	tools->b_top = tools->len + 1;
	tools->b_down = tools->len + 2;
	(tools->b_st)[0] = ST_HEAD_NBR;
	i = 1;
	while (i < tools->len + 1)
		(tools->b_st)[i++] = ST_EMPTY_NBR;
	(tools->b_st)[tools->len + 1] = ST_TOP_NBR;
	(tools->b_st)[tools->len + 2] = ST_DOWN_NBR;
	(tools->b_st)[tools->len + 3] = ST_TAIL_NBR;
	tools->b_len = 0;
}

static long	ft_set_nbr_sub(char **argv, t_tools *tools)
{
	long	temp;
	long	p;

	p = 1;
	temp = 0;
	while (ft_iswhat(argv[tools->y][tools->x], 0) == FTSPACE)
		(tools->x)++;
	if (argv[tools->y][tools->x] == '+' || argv[tools->y][tools->x] == '-')
		if (argv[tools->y][(tools->x)++] == '-')
			p = -1;
	while (ft_iswhat(argv[tools->y][tools->x], 0) == FTDIGIT)
	{
		temp = 10 * temp + p * (argv[tools->y][(tools->x)++] - '0');
		if (temp > 2147483647 || temp < -2147483648)
			exit(ft_free(tools, FTERROR));
	}
	return (temp);
}

static void	ft_set_nbr(int argc, char **argv, t_tools *tools)
{
	long	index;
	long	temp;

	tools->y = 0;
	index = 2;
	while (++(tools->y) < argc)
	{
		tools->x = 0;
		while (argv[tools->y][tools->x] != 0)
		{
			temp = ft_set_nbr_sub(argv, tools);
			if (tools->x > 0
				&& ft_iswhat(argv[tools->y][tools->x - 1], 0) == FTDIGIT)
				(tools->a_st)[index++] = temp;
		}
	}
}

void	ft_preset(t_tools *tools, int argc, char **argv)
{
	long	i;

	tools->a_st = NULL;
	tools->b_st = NULL;
	tools->answer = NULL;
	tools->w_lst = NULL;
	ft_set_len(argc, argv, tools);
	ft_set_malloc(tools);
	ft_set_nbr(argc, argv, tools);
	i = -1;
	while (++i < tools->len)
		(tools->answer)[i] = (tools->a_st)[i + 2];
	if (ft_iswhat(0, tools) == FTSORTED)
		exit(ft_free (tools, FTNORMAL));
	ft_bubble_sort(tools->answer, tools->len);
	i = 0;
	while (++i < tools->len + 1)
	{
		if (i < tools->len && (tools->answer)[i - 1] == (tools->answer)[i])
			exit(ft_free(tools, FTERROR));
		(tools->a_st)[i + 1] = \
			ft_bsearch(tools->answer, tools->len, (tools->a_st)[i + 1]);
	}
	free(tools->answer);
	tools->answer = NULL;
}
