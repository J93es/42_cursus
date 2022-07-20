#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_lst
{
	int		lst_fd;
	char	*buf;
	struct s_lst	*next;	
}	t_lst;

char	*get_next_line(int fd);
#endif