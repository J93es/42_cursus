#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#define BUFFER_SIZE 10
char	*ft_gnl_free(t_lst *gnl_lst, char **strs)
{
	t_lst	*lst_temp;
	char	*str_temp;

	while (gnl_lst != 0)
	{
		lst_temp = gnl_lst;
		gnl_lst = gnl_lst->next;
		free(lst_temp);
	}
	if (strs != 0)
	{
		while (*strs != 0)
		{
			str_temp = *strs;
			(*strs)++;
			free(str_temp);
		}
		free(strs);
	}
	return (0);
}

size_t	ft_gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len) != 0 && *(s + len) != '\n')
		len++;
	return (len);
}

char	*ft_gnl_strchr(char *s)
{
	while (*s != '\0')
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (0);
}

int	ft_gnl_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*(src + i) != 0 && *(src + i) != '\n' && dstsize > i + 1)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	return (0);
}

t_lst	*ft_find_cur_lst(t_lst	*gnl_lst, int fd)
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
		lst_temp->buf = 0;
		lst_temp->next = 0;
		gnl_lst = lst_temp;
	}
	return (gnl_lst);
}

int	ft_read_newline(char **strs, t_lst *cur_lst)
{
	int	rd_len;

	if (cur_lst->buf != 0)
	{
		*strs = (char *)malloc(ft_gnl_strlen(cur_lst->buf) + 1);
		if (*strs == 0)
			return (-1);
		ft_gnl_strlcpy(*strs, cur_lst->buf, ft_gnl_strlen(cur_lst->buf) + 1);
		cur_lst->buf = ft_gnl_strchr(cur_lst->buf);
		(*strs)++;
	}
	while (cur_lst->buf == 0)
	{
		*strs = (char *)malloc(BUFFER_SIZE + 1);
		if (*strs == 0)
			return (-1);
		rd_len = read(cur_lst->lst_fd, *strs, BUFFER_SIZE);
		*(*strs + rd_len) = 0;
		cur_lst->buf = ft_gnl_strchr(*strs);
		(*strs)++;
	}
	(*strs) = 0;
	return (0);
}

char	*ft_make_result(char **src)
{
	int		i;
	char	*result;
	char	**src_temp;
	size_t	result_len;

	result_len = 0;
	if (src == 0)
		return (0);
	src_temp = src;
	while (*src_temp != 0)
		result_len += ft_gnl_strlen((*src_temp)++);
	result = (char *)malloc(result_len + 2);
	if (result == 0)
		return (0);
	while (*src != 0)
	{
		i = 0;
		while (*(*src + i) != 0 && *(*src + i) != '\n')
			*result++ = *(*src + i++);
		(*src)++;
	}
	*result++ = '\n';
	*result = 0;
	return (result);
}

char	*get_next_line(int fd)
{
	char			*result;
	char			**strs;
	t_lst			*cur_lst;
	static t_lst	*gnl_lst;

	strs = (char **)malloc(10000);
	if (strs == 0)
		return (0);
	cur_lst = ft_find_cur_lst(gnl_lst, fd);
	if (cur_lst == 0)
		return (0);
	if (ft_read_newline(strs, cur_lst) == 1)
		return (ft_gnl_free(gnl_lst, strs));
	result = ft_make_result(strs);
	if (result == 0)
		return (ft_gnl_free(gnl_lst, strs));
	return (result);
}

#include <stdio.h>
int main(void)
{
	printf("%s", get_next_line(1));
}