#include "../inc/push_swap.h"

long	ft_bsearch(long *arr, long len, long target)
{
	long	left;
	long	right;
	long	mid;

	left = 0;
	right = len - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (target == arr[mid])
			return (mid);
		else
		{
			if (target < arr[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	return (-1);
}

long	ft_maxpos_inlen(t_tools *tools, long len, int x_flag)
{
	long	i;
	long	temp;
	long	maxpos;
	long	maxvar;
	long	*ptr;

	i = -1;
	temp = tools->a_top + 1;
	maxvar = -1;
	maxpos = 0;
	if (x_flag == AC_XA)
		ptr = tools->a_st;
	if (x_flag == AC_XB)
		ptr = tools->b_st;
	while (++i < len)
	{
		if (ptr[temp] == ST_TAIL_NBR)
			temp = 1;
		if (maxvar < ptr[temp++])
		{
			maxvar = ptr[temp - 1];
			maxpos = i;
		}
	}
	return (maxpos);
}

long	ft_minpos_inlen(t_tools *tools, long len, int x_flag)
{
	long	i;
	long	temp;
	long	minpos;
	long	minvar;
	long	*ptr;

	i = -1;
	temp = tools->a_top + 1;
	minvar = 500000000;
	minpos = 0;
	if (x_flag == AC_XA)
		ptr = tools->a_st;
	if (x_flag == AC_XB)
		ptr = tools->b_st;
	while (++i < len)
	{
		if (ptr[temp] == ST_TAIL_NBR)
			temp = 1;
		if (minvar > ptr[temp++])
		{
			minvar = ptr[temp - 1];
			minpos = i;
		}
	}
	return (minpos);
}
