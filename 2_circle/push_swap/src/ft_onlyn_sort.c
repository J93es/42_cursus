#include "../inc/push_swap.h"

static void	ft_only_two_sortx(t_tools *tools, int w_flag, int x_flag)
{
	long	maxpos;

	maxpos = ft_maxpos_inlen(tools, 2, x_flag);
	if (maxpos == 0)
		ft_action_sx(tools, w_flag, x_flag);
}

static void	ft_only_three_sortx(t_tools *tools, int w_flag, int x_flag)
{
	long	maxpos;

	maxpos = ft_maxpos_inlen(tools, 3, x_flag);
	if (maxpos == 0)
		ft_action_rx(tools, w_flag, x_flag);
	if (maxpos == 1)
		ft_action_rrx(tools, w_flag, x_flag);
	ft_only_two_sortx(tools, w_flag, x_flag);
}

static void	ft_re_onlyn_sortx(t_tools *tools, long len, int w_flag, int x_flag)
{
	long	minpos;

	if (len <= 1)
		return ;
	else if (len == 2)
		ft_only_two_sortx(tools, w_flag, x_flag);
	else if (len == 3)
		ft_only_three_sortx(tools, w_flag, x_flag);
	else
	{
		minpos = ft_minpos_inlen(tools, len, x_flag);
		if (0 < minpos && minpos <= len / 2)
			while (minpos-- > 0)
				ft_action_rx(tools, w_flag, x_flag);
		else if (0 < minpos)
		{
			minpos = len - minpos;
			while (minpos-- > 0)
				ft_action_rrx(tools, w_flag, x_flag);
		}
		ft_action_px(tools, w_flag, -1 * x_flag);
		ft_re_onlyn_sortx(tools, len - 1, w_flag, x_flag);
	}
}

void	ft_onlyn_sortx(t_tools *tools, long len, int w_flag, int x_flag)
{
	if (len <= 1)
		return ;
	else if (len == 2)
		ft_only_two_sortx(tools, w_flag, x_flag);
	else if (len == 3)
		ft_only_three_sortx(tools, w_flag, x_flag);
	else
	{
		ft_re_onlyn_sortx(tools, len, w_flag, x_flag);
		while (x_flag == AC_XA && tools->b_len > 0)
			ft_action_px(tools, w_flag, AC_XA);
		while (x_flag == AC_XB && tools->a_len > 0)
			ft_action_px(tools, w_flag, AC_XB);
	}
}
