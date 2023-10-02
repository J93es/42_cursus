#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				x_flag;
	struct s_list	*next;
}				t_list;

typedef struct s_tools
{
	long	x;
	long	y;
	long	len;
	long	*answer;
	long	*a_st;
	long	a_top;
	long	a_down;
	long	a_len;
	long	*b_st;
	long	b_top;
	long	b_down;
	long	b_len;
	t_list	*w_lst;
}				t_tools;

# define FTMERROR -1
# define FTNORMAL 0
# define FTERROR 1

# define FTNOT_WRITE 0
# define FT_WRITE 1

# define FTFALSE 0
# define FTTRUE 1
# define FTSPACE 2
# define FTDIGIT 3
# define FTSORTED 4

# define ST_EMPTY_NBR -5
# define ST_TAIL_NBR -4
# define ST_HEAD_NBR -3
# define ST_DOWN_NBR -2
# define ST_TOP_NBR -1

# define AC_RRR -6
# define AC_PB -5
# define AC_RRB -4
# define AC_RB -3
# define AC_SB -2
# define AC_XB -1
# define AC_XX 0
# define AC_XA 1
# define AC_SA 2
# define AC_RA 3
# define AC_RRA 4
# define AC_PA 5
# define AC_RR 6
# define AC_SS	7

int		ft_iswhat(int c, t_tools *tools);
int		ft_free(t_tools *tools, int opt);
void	ft_preset(t_tools *tools, int argc, char **argv);
long	ft_bsearch(long *arr, long len, long target);
long	ft_maxpos_inlen(t_tools *tools, long len, int x_flag);
long	ft_minpos_inlen(t_tools *tools, long len, int x_flag);
void	ft_binary_rsort(t_tools *tools, int w_flag);
void	ft_bubble_sort(long *arr, long len);
void	ft_onlyn_sortx(t_tools *tools, long len, int flag, int x_flag);
void	ft_action_sx(t_tools *tools, int w_flag, int x_flag);
void	ft_action_px(t_tools *tools, int w_flag, int x_flag);
void	ft_action_rx(t_tools *tools, int w_flag, int x_flag);
void	ft_action_rrx(t_tools *tools, int w_flag, int x_flag);
t_list	*ft_lstnew(int content, t_tools *tools);
void	ft_lstadd_back(t_tools *tools, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstwrite(t_list *w_lst);
#endif
