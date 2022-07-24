#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	ft_gnl_strlcpy(char *dst, char *src, long dstsize)
{
	long	i;

	i = 0;
	while (*(src + i) != '\0' && i + 1 < dstsize)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (dstsize > 0)
		*(dst + i) = 0;
}

char	*ft_gnl_strdup(const char *s1)
{
	long	s1_len;
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

char	*ft_gnl_strchr(char *s)
{
	int		opt;
	char	*ptr;
	char	*temp;

	opt = 0;
	ptr = s;
	while (*ptr != 0)
	{
		if (*ptr == '\n' && opt == 0)
		{
			opt = 1;
			temp = ft_gnl_strdup(ptr + 1);
		}
		ptr++;
	}
	if (opt == 0)
		return (ft_gnl_strdup("\0"));
	else
		return (temp);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*dst;
	char	*ptr;
	long	s1_len;
	long	s2_len;

	s1_len = 0;
	s2_len = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	while (*(s1 + s1_len) != 0 && *(s1 + s1_len) != '\n')
		s1_len++;
	while (*(s2 + s2_len) != 0 && *(s2 + s2_len) != '\n')
		s2_len++;
	dst = (char *)malloc(s1_len + s2_len + 2);
	if (dst == 0)
		return (0);
	ptr = dst;
	while (*s1 != 0 && *s1 != '\n')
		*ptr++ = *s1++;
	while (*s2 != 0 && *s2 != '\n')
		*ptr++ = *s2++;
	*ptr = 0;
	return (dst);
}

int	gnl_strlisin(char *str, long len)
{
	while (len-- > 0)
	{
		if (*str == '\n' || *str == 0)
			return (1);
		str++;
	}
	return (0);
}

void	*gnl_free(void **ptr_free, int flag, int target)
{
	if (flag == SINGLE_FREE && ptr_free[target] != 0)
	{
		free (ptr_free[target]);
		ptr_free[target] = 0;
	}
	if (flag == FINISH_FREE)
		gnl_free(ptr_free, SINGLE_FREE, BUF_PTR);
	if (flag == ERROR_FREE)
	{
		gnl_free(ptr_free, SINGLE_FREE, BUF_PTR);
		gnl_free(ptr_free, SINGLE_FREE, NEW_LINE_PTR);
		gnl_free(ptr_free, SINGLE_FREE, STR_PTR);
	}
	return (0);
}

static char	*gnl_handle_buf(char **buf, char **new_line, void *ptr_free[PTR_FREE_LEN])
{
	char	*buf_temp;
	char	*new_line_temp;

	ptr_free[BUF_PTR] = *buf;
	*buf = ft_gnl_strchr(*buf);
	gnl_free(ptr_free, SINGLE_FREE, BUF_PTR);
	if ((ptr_free[BUF_PTR] = *buf) == 0)
		return (gnl_free(ptr_free, ERROR_FREE, -1));
	buf_temp = *buf;
	new_line_temp = *new_line;
	while (*buf_temp != 0)
	{
		if (*buf_temp == '\n')
			break ;
		*new_line_temp++ = *buf_temp++;
	}
	*new_line_temp = 0;
	return (*new_line);
}

static char *gnl_handle_read(char **buf, char **new_line, int fd, void **ptr_free)
{
	long	rd_size;
	char	*str;

	rd_size = 1;
	str = (char *)malloc(BUFFER_SIZE + 1);
	if ((ptr_free[STR_PTR] = str) == 0)
		return (gnl_free(ptr_free, ERROR_FREE, -1));
	*str = 0;
	while (rd_size > 0)
	{
		rd_size = read(fd, str, BUFFER_SIZE);
		*(str + rd_size) = 0;
		ptr_free[NEW_LINE_PTR] = *new_line;
		*new_line = ft_gnl_strjoin(*new_line, str);
		gnl_free(ptr_free, SINGLE_FREE, NEW_LINE_PTR);
		if ((ptr_free[NEW_LINE_PTR] = *new_line) == 0)
			return (gnl_free(ptr_free, ERROR_FREE, -1));
		if (gnl_strlisin(str, rd_size) == 1)
			break ;
	}
	ft_gnl_strlcpy(*buf, str, rd_size + 1);
	gnl_free(ptr_free, SINGLE_FREE, STR_PTR);
	if (rd_size == 0)
		gnl_free(ptr_free, FINISH_FREE, -1);
	return (*new_line);
}

char	*get_next_line(int fd)
{
	char			*ptr;
	char			*new_line;
	void			*ptr_free[PTR_FREE_LEN];
	static char		*buf;

	ptr_free[BUF_PTR] = 0;
	ptr_free[NEW_LINE_PTR] = 0;
	ptr_free[STR_PTR] = 0;
	new_line = (char *)malloc(BUFFER_SIZE + 1);
	if ((ptr_free[NEW_LINE_PTR] = new_line) == 0)
		return (gnl_free(ptr_free, ERROR_FREE, -1));
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, new_line, 0) < 0)
		return (gnl_free(ptr_free, ERROR_FREE, -1));
	if (buf == 0)
		buf = (char *)malloc(BUFFER_SIZE + 1);
	if ((ptr_free[BUF_PTR] = buf) == 0)
		return (gnl_free(ptr_free, ERROR_FREE, -1));
	if (gnl_handle_buf(&buf, &new_line, ptr_free) == 0)
		return (0);
	if (gnl_handle_read(&buf, &new_line, fd, ptr_free) == 0)
		return (0);
	ptr = new_line;
	while (*ptr != 0)
		ptr++;
	*ptr++ = '\n';
	*ptr = 0;
	return (new_line);
}


#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int fd;
	printf("%s", get_next_line(fd = open("./files/41_no_nl", O_RDONLY)));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}