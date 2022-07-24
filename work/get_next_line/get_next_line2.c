#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

//#define BUFFER_SIZE 4

#define PTR_FREE_LEN 7
#define TEMP_PTR 0
#define BACKUP_PTR 1
#define CUR_LST_BUF_PTR 2
#define CUR_LST_PTR 3
#define GNL_LST_PTR 4
#define RESULT_PTR 5
#define RD_SIZE_PTR 6

#define SINGLE_FREE 0
#define CUR_LST_FREE 1
#define ERROR_FREE 2
#define FINISH_FREE 3

void	*ft_free(void *ptr_free[PTR_FREE_LEN], int opt, int index);
void	ft_other_free(void *ptr_free[PTR_FREE_LEN], int opt);

void	*ft_free(void *ptr_free[PTR_FREE_LEN], int opt, int index)
{
	t_lst	*cur_lst;

	cur_lst = ptr_free[CUR_LST_PTR];
	if (opt == SINGLE_FREE && ptr_free[index] != 0)
	{
		free (ptr_free[index]);
		ptr_free[index] = 0;
	}
	if (opt == CUR_LST_FREE)
	{
		if (cur_lst != 0)
		{
			while (cur_lst-> next != 0 && ((t_lst *)ptr_free[CUR_LST_PTR])->lst_fd != cur_lst->lst_fd)
				cur_lst = cur_lst->next;
			ptr_free[CUR_LST_PTR] = cur_lst;
		}
		ft_free(ptr_free, SINGLE_FREE, CUR_LST_BUF_PTR);
		ft_free(ptr_free, SINGLE_FREE, CUR_LST_PTR);
	}
	if (opt == FINISH_FREE)
		ft_other_free(ptr_free, FINISH_FREE);
	if (opt == ERROR_FREE)
		ft_other_free(ptr_free, ERROR_FREE);
	return (0);
}

void	ft_other_free(void *ptr_free[PTR_FREE_LEN], int opt)
{
	t_lst	*gnl_lst;

	gnl_lst = ptr_free[GNL_LST_PTR];
	if (opt == FINISH_FREE)
		ft_free(ptr_free, CUR_LST_FREE, -1);
	if (opt == ERROR_FREE)
	{
		ft_free(ptr_free, SINGLE_FREE, RESULT_PTR);
		while (gnl_lst != 0)
		{
			ptr_free[CUR_LST_PTR] = gnl_lst;
			ft_free(ptr_free, CUR_LST_FREE, -1);
			gnl_lst = gnl_lst->next;
		}
	}
	ft_free(ptr_free, SINGLE_FREE, BACKUP_PTR);
}

int	ft_isin_strl(char *str, size_t len)
{
	while (len-- > 0)
	{
		if (*str == '\n' || *str == 0)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dst;
	char	*ptr;

	s1_len = 0;
	while (*(s1 + s1_len) != 0)
		s1_len++;
	dst = (char *)malloc(s1_len + 2);
	if (dst == 0)
		return (0);
	ptr = dst;
	while (*s1 != 0)
		*ptr++ = *s1++;
	*ptr = 0;
	return (dst);
}

char	*ft_strchr(const char *s)
{
	while (*s != 0)
	{
		if (*s == '\n')
			return (ft_strdup(s + 1));
		s++;
	}
	return (ft_strdup("\0"));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	while (*(s1 + s1_len) != 0)
		s1_len++;
	while (*(s2 + s2_len) != 0)
		s2_len++;
	dst = (char *)malloc(s1_len + s2_len + 2);
	if (dst == 0)
		return (0);
	ptr = dst;
	while (*s1 != 0)
		*ptr++ = *s1++;
	while (*s2 != 0)
		*ptr++ = *s2++;
	*ptr = 0;
	return (dst);
}

t_lst	*ft_gnl_find_cur_lst(t_lst **gnl_lst, int fd, void *ptr_free[PTR_FREE_LEN])
{
	t_lst	**cur_lst;

	cur_lst = gnl_lst;
	while ((*cur_lst) != 0 && (*cur_lst)->lst_fd != fd)
		(*cur_lst) = (*cur_lst)->next;
	if ((*cur_lst) == 0)
	{
		(*cur_lst) = (t_lst *)malloc(sizeof(t_lst));
		if ((ptr_free[CUR_LST_PTR] = cur_lst) == 0)
			return (ft_free(ptr_free, ERROR_FREE, -1));
		(*cur_lst)->lst_fd = fd;
		(*cur_lst)->buf = ft_strdup("\0");
		if ((ptr_free[CUR_LST_BUF_PTR] = (*cur_lst)->buf) == 0)
			return (ft_free(ptr_free, ERROR_FREE, -1));
		(*cur_lst)->next = 0;
	}
	return (*cur_lst);
}

char	*ft_gnl_handle_buf(t_lst **cur_lst, void *ptr_free[PTR_FREE_LEN])
{
	char	*result;
	char	*temp;

	result = ft_strdup((const char *)(*cur_lst)->buf);
	if ((ptr_free[RESULT_PTR] = result) == 0)
		return (ft_free(ptr_free, ERROR_FREE, -1));
	temp = result;
	while (*temp != 0 && *temp != '\n')
		temp++;
	*temp = 0;
	(*cur_lst)->buf = ft_strchr((*cur_lst)->buf);
	ft_free(ptr_free, SINGLE_FREE, CUR_LST_BUF_PTR);
	if ((ptr_free[CUR_LST_BUF_PTR] = (*cur_lst)->buf) == 0)
		return (ft_free(ptr_free, ERROR_FREE, -1));
	return (result);
}

char	*ft_gnl_handle_read(t_lst **cur_lst, char *result, void *ptr_free[PTR_FREE_LEN])
{
	int		rd_size;
	char	*backup;

	backup = (char *)malloc(BUFFER_SIZE + 1);
	if ((ptr_free[BACKUP_PTR] = backup) == 0)
		return (ft_free(ptr_free, ERROR_FREE, -1));
	rd_size = read((*cur_lst)->lst_fd, backup, BUFFER_SIZE);
	*(backup + rd_size) = 0;
	while (rd_size > 0)
	{
		result = ft_strjoin(result, backup);
		ft_free(ptr_free, SINGLE_FREE, RESULT_PTR);
		if ((ptr_free[RESULT_PTR] = result) == 0)
			return (ft_free(ptr_free, ERROR_FREE, -1));
		if (ft_isin_strl(backup, rd_size == 1))
			break ;
		rd_size = read((*cur_lst)->lst_fd, backup, BUFFER_SIZE);
		*(backup + rd_size) = 0;
	}
	(*cur_lst)->buf = ft_strdup(backup);
	ft_free(ptr_free, SINGLE_FREE, CUR_LST_BUF_PTR);
	if ((ptr_free[CUR_LST_BUF_PTR] = (*cur_lst)->buf) == 0)
		return (ft_free(ptr_free, ERROR_FREE, -1));
	ft_free(ptr_free, SINGLE_FREE, BACKUP_PTR);
	if (rd_size <= 0)
		ptr_free[RD_SIZE_PTR] = 0;
	return (result);
}

char	*get_next_line(int fd)
{
	void			*ptr_free[PTR_FREE_LEN];
	char			*result;
	char			*temp;
	t_lst			*cur_lst;
	static t_lst	*gnl_lst;

	ptr_free[RD_SIZE_PTR] = "1";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if ((cur_lst = ft_gnl_find_cur_lst(&gnl_lst, fd, ptr_free)) == 0)
		return (ft_free(ptr_free, ERROR_FREE, -1));
	if ((result = ft_gnl_handle_buf(&cur_lst, ptr_free)) == 0)
		return (ft_free(ptr_free, ERROR_FREE, -1));
	if ((result = ft_gnl_handle_read(&cur_lst, result, ptr_free)) == 0)
		return (ft_free(ptr_free, ERROR_FREE, -1));
	temp = result;
	while (*temp != 0 && *temp != '\n')
		temp++;
	*temp++ = '\n';
	*temp = 0;
	if (ptr_free[RD_SIZE_PTR] == 0)
		ft_free (ptr_free, FINISH_FREE, -1);
	return (result);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int fd;
	printf("%s", get_next_line(fd = open("test", O_RDONLY)));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}*/