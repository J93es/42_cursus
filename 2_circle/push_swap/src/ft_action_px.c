#include "../inc/push_swap.h"

static void	ft_action_pa(t_tools *tools)
{
	long	i;

	(tools->b_st)[tools->b_top] = ST_EMPTY_NBR;
	if ((tools->b_st)[tools->b_top + 1] == ST_TAIL_NBR)
	{
		i = (tools->b_st)[1];
		(tools->b_st)[1] = ST_TOP_NBR;
		tools->b_top = 1;
	}
	else
	{
		i = (tools->b_st)[tools->b_top + 1];
		(tools->b_st)[++(tools->b_top)] = ST_TOP_NBR;
	}
	(tools->a_st)[tools->a_top] = i;
	if ((tools->a_st)[tools->a_top - 1] == ST_HEAD_NBR)
	{
		(tools->a_st)[tools->len + 2] = ST_TOP_NBR;
		tools->a_top = tools->len + 2;
	}
	else
		(tools->a_st)[--(tools->a_top)] = ST_TOP_NBR;
	(tools->a_len)++;
	(tools->b_len)--;
}

static void	ft_action_pb(t_tools *tools)
{
	long	i;

	(tools->a_st)[tools->a_top] = ST_EMPTY_NBR;
	if ((tools->a_st)[tools->a_top + 1] == ST_TAIL_NBR)
	{
		i = (tools->a_st)[1];
		(tools->a_st)[1] = ST_TOP_NBR;
		tools->a_top = 1;
	}
	else
	{
		i = (tools->a_st)[tools->a_top + 1];
		(tools->a_st)[++(tools->a_top)] = ST_TOP_NBR;
	}
	(tools->b_st)[tools->b_top] = i;
	if ((tools->b_st)[tools->b_top - 1] == ST_HEAD_NBR)
	{
		(tools->b_st)[tools->len + 2] = ST_TOP_NBR;
		tools->b_top = tools->len + 2;
	}
	else
		(tools->b_st)[--(tools->b_top)] = ST_TOP_NBR;
	(tools->a_len)--;
	(tools->b_len)++;
}

void	ft_action_px(t_tools *tools, int w_flag, int x_flag)
{
	if (x_flag == AC_XA)
	{
		if (tools->a_len == tools->len || tools->b_len == 0)
			return ;
		if (w_flag == FT_WRITE)
			ft_lstadd_back(tools, ft_lstnew(AC_PA, tools));
		ft_action_pa(tools);
	}
	if (x_flag == AC_XB)
	{
		if (tools->a_len == 0 || tools->b_len == tools->len)
			return ;
		if (w_flag == FT_WRITE)
			ft_lstadd_back(tools, ft_lstnew(AC_PB, tools));
		ft_action_pb(tools);
	}
}
