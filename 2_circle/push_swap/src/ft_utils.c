#include "../inc/push_swap.h"

int	ft_iswhat(int c, t_tools *tools)
{
	long	i;

	i = 0;
	if (tools == 0)
	{
		if (c == ' ' || c == '\n' || c == '\t'
			|| c == '\r' || c == '\v' || c == '\r')
			return (FTSPACE);
		if ('0' <= c && c <= '9')
			return (FTDIGIT);
	}
	else
	{
		while (++i < tools->len)
		{
			if ((tools->answer)[i - 1] > (tools->answer)[i])
				break ;
			if ((tools->answer)[i - 1] == (tools->answer)[i])
				exit(ft_free(tools, FTERROR));
		}
		if (i == tools->len)
			return (FTSORTED);
	}
	return (FTFALSE);
}

int	ft_free(t_tools *tools, int opt)
{
	t_list	*ptr;
	t_list	*temp;

	ptr = tools->w_lst;
	if (tools->answer != NULL)
		free(tools->answer);
	tools->answer = NULL;
	if (tools->a_st != NULL)
		free(tools->a_st);
	tools->a_st = NULL;
	if (tools->b_st != NULL)
		free(tools->b_st);
	tools->b_st = NULL;
	while (ptr != NULL)
	{
		temp = ptr;
		ptr = ptr->next;
		temp->x_flag = 0;
		free(temp);
		temp = NULL;
	}
	if (opt == FTERROR)
		write(2, "Error\n", 6);
	return (opt);
}
