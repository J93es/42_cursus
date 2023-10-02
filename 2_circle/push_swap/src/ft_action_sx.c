#include "../inc/push_swap.h"

static void	ft_action_sa(t_tools *tools)
{
	long	pos_x;
	long	pos_y;
	long	temp;

	if (tools->a_len < 2)
		return ;
	pos_x = tools->a_top + 1;
	if ((tools->a_st)[pos_x] == ST_TAIL_NBR)
		pos_x = 1;
	pos_y = pos_x + 1;
	if ((tools->a_st)[pos_y] == ST_TAIL_NBR)
		pos_y = 1;
	temp = (tools->a_st)[pos_x];
	(tools->a_st)[pos_x] = (tools->a_st)[pos_y];
	(tools->a_st)[pos_y] = temp;
}

static void	ft_action_sb(t_tools *tools)
{
	long	pos_x;
	long	pos_y;
	long	temp;

	if (tools->b_len < 2)
		return ;
	pos_x = tools->b_top + 1;
	if ((tools->b_st)[pos_x] == ST_TAIL_NBR)
		pos_x = 1;
	pos_y = pos_x + 1;
	if ((tools->b_st)[pos_y] == ST_TAIL_NBR)
		pos_y = 1;
	temp = (tools->b_st)[pos_x];
	(tools->b_st)[pos_x] = (tools->b_st)[pos_y];
	(tools->b_st)[pos_y] = temp;
}

static void	ft_action_ss(t_tools *tools)
{
	if (tools->a_len > 1)
		ft_action_sa(tools);
	if (tools->b_len > 1)
		ft_action_sb(tools);
}

void	ft_action_sx(t_tools *tools, int w_flag, int x_flag)
{
	if (x_flag == AC_XA)
	{
		if (tools->a_len < 2)
			return ;
		if (w_flag == FT_WRITE)
			ft_lstadd_back(tools, ft_lstnew(AC_SA, tools));
		ft_action_sa(tools);
	}
	if (x_flag == AC_XB)
	{
		if (tools->b_len < 2)
			return ;
		if (w_flag == FT_WRITE)
			ft_lstadd_back(tools, ft_lstnew(AC_SB, tools));
		ft_action_sb(tools);
	}
	if (x_flag == AC_XX)
	{
		if (w_flag == FT_WRITE && (tools->a_len > 1 || tools->b_len > 1))
			ft_lstadd_back(tools, ft_lstnew(AC_SS, tools));
		ft_action_ss(tools);
	}
}
