#include "../inc/push_swap.h"

static void	ft_action_rra(t_tools *tools)
{
	long	i;

	(tools->a_st)[tools->a_down] = ST_EMPTY_NBR;
	if ((tools->a_st)[tools->a_down - 1] == ST_HEAD_NBR)
	{
		i = (tools->a_st)[tools->len + 2];
		(tools->a_st)[tools->len + 2] = ST_DOWN_NBR;
		tools->a_down = tools->len + 2;
	}
	else
	{
		i = (tools->a_st)[tools->a_down - 1];
		(tools->a_st)[--(tools->a_down)] = ST_DOWN_NBR;
	}
	(tools->a_st)[tools->a_top] = i;
	if ((tools->a_st)[tools->a_top - 1] == ST_HEAD_NBR)
	{
		(tools->a_st)[tools->len + 2] = ST_TOP_NBR;
		tools->a_top = tools->len + 2;
	}
	else
		(tools->a_st)[--(tools->a_top)] = ST_TOP_NBR;
}

static void	ft_action_rrb(t_tools *tools)
{
	long	i;

	(tools->b_st)[tools->b_down] = ST_EMPTY_NBR;
	if ((tools->b_st)[tools->b_down - 1] == ST_HEAD_NBR)
	{
		i = (tools->b_st)[tools->len + 2];
		(tools->b_st)[tools->len + 2] = ST_DOWN_NBR;
		tools->b_down = tools->len + 2;
	}
	else
	{
		i = (tools->b_st)[tools->b_down - 1];
		(tools->b_st)[--(tools->b_down)] = ST_DOWN_NBR;
	}
	(tools->b_st)[tools->b_top] = i;
	if ((tools->b_st)[tools->b_top - 1] == ST_HEAD_NBR)
	{
		(tools->b_st)[tools->len + 2] = ST_TOP_NBR;
		tools->b_top = tools->len + 2;
	}
	else
		(tools->b_st)[--(tools->b_top)] = ST_TOP_NBR;
}

static void	ft_action_rrr(t_tools *tools)
{
	if (tools->a_len > 1)
		ft_action_rra(tools);
	if (tools->b_len > 1)
		ft_action_rrb(tools);
}

void	ft_action_rrx(t_tools *tools, int w_flag, int x_flag)
{
	if (x_flag == AC_XA)
	{
		if (tools->a_len < 2)
			return ;
		if (w_flag == FT_WRITE)
			ft_lstadd_back(tools, ft_lstnew(AC_RRA, tools));
		ft_action_rra(tools);
	}
	if (x_flag == AC_XB)
	{
		if (tools->b_len < 2)
			return ;
		if (w_flag == FT_WRITE)
			ft_lstadd_back(tools, ft_lstnew(AC_RRB, tools));
		ft_action_rrb(tools);
	}
	if (x_flag == AC_XX)
	{
		if (w_flag == FT_WRITE && (tools->a_len > 1 || tools->b_len > 1))
			ft_lstadd_back(tools, ft_lstnew(AC_RRR, tools));
		ft_action_rrr(tools);
	}
}
