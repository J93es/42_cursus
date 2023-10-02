#include "../inc/push_swap.h"

t_list	*ft_lstnew(int content, t_tools *tools)
{
	t_list	*dst;

	dst = (t_list *)malloc(sizeof(t_list));
	if (dst == 0)
		exit(ft_free(tools, FTMERROR));
	dst->x_flag = content;
	dst->next = 0;
	return (dst);
}

void	ft_lstadd_back(t_tools *tools, t_list *new)
{
	t_list	*temp;

	temp = 0;
	if (tools->w_lst == NULL)
	{
		tools->w_lst = new;
		return ;
	}
	temp = (tools->w_lst);
	while (temp->next != 0)
		temp = temp->next;
	temp->next = new;
}

static void	ft_writing(int flag, int opt)
{
	if (opt == 0 && flag == AC_SA)
		write(1, "sa\n", 3);
	if (opt == 0 && flag == AC_SB)
		write(1, "sb\n", 3);
	if (opt == 0 && flag == AC_PA)
		write(1, "pa\n", 3);
	if (opt == 0 && flag == AC_PB)
		write(1, "pb\n", 3);
	if (opt == 0 && flag == AC_RA)
		write(1, "ra\n", 3);
	if (opt == 0 && flag == AC_RB)
		write(1, "rb\n", 3);
	if (opt == 0 && flag == AC_RRA)
		write(1, "rra\n", 4);
	if (opt == 0 && flag == AC_RRB)
		write(1, "rrb\n", 4);
	if (opt == 1 && (flag == AC_SA || flag == AC_SB))
		write(1, "ss\n", 3);
	if (opt == 1 && (flag == AC_RA || flag == AC_RB))
		write(1, "rr\n", 3);
	if (opt == 1 && (flag == AC_RRA || flag == AC_RRB))
		write(1, "rrr\n", 4);
}

static void	ft_lstwrite_exept(int first_flag, \
		int second_flag, int first_len, int second_len)
{
	if (first_flag == AC_PA || first_flag == AC_PB)
	{
		if (first_len > second_len)
			while (first_len-- > second_len)
				ft_writing(first_flag, 0);
		else
			while (second_len-- > first_len)
				ft_writing(second_flag, 0);
		return ;
	}
	if (first_len > second_len)
	{
		while (first_len-- > second_len)
			ft_writing(first_flag, 0);
		while (first_len-- > -1)
			ft_writing(first_flag, 1);
	}
	else
	{
		while (second_len-- > first_len)
			ft_writing(second_flag, 0);
		while (second_len-- > -1)
			ft_writing(second_flag, 1);
	}
}

void	ft_lstwrite(t_list *w_lst)
{
	int		first_flag;
	int		second_flag;
	long	first_len;
	long	second_len;
	t_list	*ptr;

	ptr = w_lst;
	while (ptr != NULL)
	{
		first_len = 0;
		second_len = 0;
		first_flag = ptr->x_flag;
		while (ptr != NULL && first_flag == ptr->x_flag && ++first_len > 0)
			ptr = ptr->next;
		if (ptr != NULL)
			second_flag = ptr->x_flag;
		while (ptr != NULL && first_len != 0
			&& -1 * first_flag == ptr->x_flag && ++second_len > 0)
			ptr = ptr->next;
		if (second_len == 0)
			while (first_len-- > 0)
				ft_writing(first_flag, 0);
		else
			ft_lstwrite_exept(first_flag, second_flag, first_len, second_len);
	}
}
