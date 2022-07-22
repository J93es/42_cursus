#include <stdlib.h>
#include "get_next_line.h"

t_lst	*ft_find_cur_lst(t_lst *gnl_lst, int fd)
{
	t_lst	*lst_temp;

	while (gnl_lst != 0 && gnl_lst->lst_fd != fd)
		gnl_lst = gnl_lst->next;
	if (gnl_lst == 0)
	{
		lst_temp = (t_lst *)malloc(sizeof(t_lst));
		if (lst_temp == 0)
			return (0);
		lst_temp->lst_fd = fd;
		buf =
		lst_temp->buf = 0;
		lst_temp->next = 0;
		gnl_lst = lst_temp;
	}
	return (gnl_lst);
}

char	*get_next_line(int fd)
{
	size_t			rd_len;
	char			*new_line;
	char			*temp;
	t_lst			cur_lst;
	static t_lst	gnl_lst;

	cur_lst = 0;
	gnl_lst = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	cur_lst = ft_find_cur_lst(gnl_lst, fd);
	if (cur_lst == 0)
		return (-1);
	if (cur_lst->(*buf) != 0)
		new_line = strdup(cur_lst->(*buf));
	cur_lst->(*buf) = (char *)malloc(BUFFER_SIZE + 1);
	if (cur_lst->buf == 0)
		return (-1);
	while (rd_len = read(fd, cur_lst->buf, BUFFER_SIZE) != 0 && cur_lst->buf == 0)
	{
		temp = new_line;
		new_line = strjoin(new_line, cur_lst->buf);
	}
}