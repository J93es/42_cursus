#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "get_next_line_bonus.h"

#if OPEN_MAX > 100000
#define MAX 100000
#else
#define MAX OPEN_MAX
#endif

static void	*gnl_free(char **ptr, int status)
{
	long	i;

	i = -1;
	if (ptr == 0)
		return (0);
	if (status == GNLB_NORMAL)
	{
		if (*ptr == 0)
			return (0);
		free(*ptr);
		*ptr = 0;
	}
	if (status == GNLB_M_ERROR)
	{
		while (++i < MAX + 2)
			if (ptr[i] != 0)
			{
				free(ptr[i]);
				ptr[i] = 0;
			}
	}
	return (0);
}

static char	*ft_trim_tail(char *new_line, char status[1])
{
	int		i;
	char	*str;

	i = 0;
	if (new_line[0] == 0)
		return(gnl_free(&new_line, GNLB_NORMAL));
	while (new_line[i] != 0 && new_line[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (str == 0)
	{
		*status = GNLB_M_ERROR;
		return (gnl_free(&new_line, GNLB_NORMAL));
	}
	i = 0;
	while (new_line[i] != 0 && new_line[i] != '\n')
	{
		str[i] = new_line[i];
		i++;
	}
	if (new_line[i] == '\n')
		str[i++] = '\n';
	str[i] = 0;
	gnl_free(&new_line, GNLB_NORMAL);
	return (str);
}

static char	*ft_trim_head(char *buf, char status[1])
{
	int		i;
	char	*new_buf;

	i = 0;
	while (buf[i] != 0 && buf[i] != '\n')
		i++;
	if (buf[i] == 0)
		return (gnl_free(&buf, GNLB_NORMAL));
	new_buf = ft_strdup(ft_strchr(buf, '\n') + 1);
	if (new_buf == 0)
	{
		*status = GNLB_M_ERROR;
		return (gnl_free(&buf, GNLB_NORMAL));
	}
	gnl_free(&buf, GNLB_NORMAL);
	return (new_buf);
}

static char	*ft_handle_read(int fd, char *buf, char status[1])
{
	char	*str;
	int		rd_bytes;

	str = (char *)malloc(BUFFER_SIZE + 1);
	if (str == 0 && (*status = GNLB_M_ERROR) != -1)
		return (gnl_free(&buf, GNLB_NORMAL));
	rd_bytes = 1;
	while (ft_strchr(buf, '\n') == 0 && rd_bytes > 0)
	{
		rd_bytes = read(fd, str, BUFFER_SIZE);
		if (rd_bytes < 0 && (*status = GNLB_RD_ERROR) != -1)
		{
			if (buf != 0)
				gnl_free(&buf, GNLB_NORMAL);
			return(gnl_free(&str, GNLB_NORMAL));
		}
		str[rd_bytes] = 0;
		buf = ft_strjoin(buf, str);
		if (buf == 0 && (*status = GNLB_M_ERROR) != -1)
			return(gnl_free(&str, GNLB_NORMAL));
	}
	gnl_free(&str, GNLB_NORMAL);
	return (buf);
}

char	*get_next_line(int fd)
{
	char		status[1];
	char		*new_line;
	static char	*buf[MAX + 2];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, status, 0) < 0)
		return (0);
	*status = GNLB_NORMAL;
	buf[fd] = ft_handle_read(fd, buf[fd], status);
	if (*status == GNLB_M_ERROR)
		return (gnl_free(buf, GNLB_M_ERROR));
	if (*status == GNLB_RD_ERROR)
		return (0);
	new_line = ft_strdup(buf[fd]);
	if (new_line == 0)
		return (gnl_free(buf, GNLB_M_ERROR));
	buf[fd] = ft_trim_head(buf[fd], status);
	if (*status == GNLB_M_ERROR)
	{
		gnl_free(buf, GNLB_M_ERROR);
		return (gnl_free(&new_line, GNLB_NORMAL));
	}
	new_line = ft_trim_tail(new_line, status);
	if (*status == GNLB_M_ERROR)
		return (gnl_free(buf, GNLB_M_ERROR));
	return (new_line);
}
