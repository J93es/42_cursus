#include "../inc/push_swap.h"

static void	ft_action_ra(t_tools *tools)
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
	(tools->a_st)[tools->a_down] = i;
	if ((tools->a_st)[tools->a_down + 1] == ST_TAIL_NBR)
	{
		(tools->a_st)[1] = ST_DOWN_NBR;
		tools->a_down = 1;
	}
	else
		(tools->a_st)[++(tools->a_down)] = ST_DOWN_NBR;
}

static void	ft_action_rb(t_tools *tools)
{
	long	i;

	(tools->b_st)[tools->b_top] = ST_EMPTY_NBR;
	if ((tools->a_st)[tools->b_top + 1] == ST_TAIL_NBR)
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
	(tools->b_st)[tools->b_down] = i;
	if ((tools->b_st)[tools->b_down + 1] == ST_TAIL_NBR)
	{
		(tools->b_st)[1] = ST_DOWN_NBR;
		tools->b_down = 1;
	}
	else
		(tools->b_st)[++(tools->b_down)] = ST_DOWN_NBR;
}

static void	ft_action_rr(t_tools *tools)
{
	if (tools->a_len > 1)
		ft_action_ra(tools);
	if (tools->b_len > 1)
		ft_action_rb(tools);
}

void	ft_action_rx(t_tools *tools, int w_flag, int x_flag)
{
	if (x_flag == AC_XA)
	{
		if (tools->a_len < 2)
			return ;
		if (w_flag == FT_WRITE)
			ft_lstadd_back(tools, ft_lstnew(AC_RA, tools));
		ft_action_ra(tools);
	}
	if (x_flag == AC_XB)
	{
		if (tools->b_len < 2)
			return ;
		if (w_flag == FT_WRITE)
			ft_lstadd_back(tools, ft_lstnew(AC_RB, tools));
		ft_action_rb(tools);
	}
	if (x_flag == AC_XX)
	{
		if (w_flag == FT_WRITE && (tools->a_len > 1 || tools->b_len > 1))
			ft_lstadd_back(tools, ft_lstnew(AC_RR, tools));
		ft_action_rr(tools);
	}
}
