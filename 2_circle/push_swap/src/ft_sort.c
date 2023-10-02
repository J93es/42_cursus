#include "../inc/push_swap.h"

static long	ft_binary_digit(long n, int digit)
{
	int		i;
	long	arr[40];

	i = 0;
	while (i < 33)
		arr[i++] = 0;
	i = 0;
	while (n != 0)
	{
		arr[i++] = n % 2;
		n /= 2;
	}
	return (arr[digit]);
}

static void	ft_binary_rsort_sub(t_tools *tools,
		long max_digit, long cur_digit, int w_flag)
{
	long	len;
	long	pos;

	len = tools->a_len + 1;
	while (--len > 0)
	{
		pos = tools->a_top + 1;
		if ((tools->a_st)[pos] == ST_TAIL_NBR)
			pos = 1;
		if (ft_binary_digit((tools->a_st)[pos], cur_digit) == 0)
			ft_action_px(tools, w_flag, AC_XB);
		else
			ft_action_rx(tools, w_flag, AC_XA);
	}
	len = tools->b_len + 1;
	while (cur_digit < max_digit - 1 && --len > 0)
	{
		pos = tools->b_top + 1;
		if ((tools->b_st)[pos] == ST_TAIL_NBR)
			pos = 1;
		if (ft_binary_digit((tools->b_st)[pos], cur_digit + 1) == 0)
			ft_action_rx(tools, w_flag, AC_XB);
		else
			ft_action_px(tools, w_flag, AC_XA);
	}
}

void	ft_binary_rsort(t_tools *tools, int w_flag)
{
	long	max_digit;
	long	cur_digit;
	long	num;

	max_digit = 0;
	cur_digit = 0;
	num = tools->len - 1;
	while (num > 0)
	{
		num /= 2;
		max_digit++;
	}
	while (cur_digit < max_digit)
	{
		ft_binary_rsort_sub(tools, max_digit, cur_digit, w_flag);
		cur_digit++;
	}
	while (tools->b_len > 0)
		ft_action_px(tools, w_flag, AC_XA);
}

void	ft_bubble_sort(long *arr, long len)
{
	long	i;
	long	j;
	long	temp;

	i = -1;
	while (++i < len - 1)
	{
		j = -1;
		while (++j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
