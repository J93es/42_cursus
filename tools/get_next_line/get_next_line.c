/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:21:33 by mijung            #+#    #+#             */
/*   Updated: 2022/07/27 12:22:46 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static void	*ft_free(char **ptr)
{
	if (*ptr == 0)
		return (0);
	free(*ptr);
	*ptr = 0;
	return (0);
}

static char	*ft_trim_tail(char *new_line, char m_status[1])
{
	int		i;
	char	*str;

	i = 0;
	if (new_line[0] == 0)
		return (ft_free(&new_line));
	while (new_line[i] != 0 && new_line[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (str == 0)
	{
		*m_status = GNL_M_ERROR;
		return (ft_free(&new_line));
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
	ft_free(&new_line);
	return (str);
}

static char	*ft_trim_head(char *buf, char m_status[1])
{
	int		i;
	char	*new_buf;

	i = 0;
	while (buf[i] != 0 && buf[i] != '\n')
		i++;
	if (buf[i] == 0)
		return (ft_free(&buf));
	new_buf = ft_strdup_gnl(ft_strchr_gnl(buf, '\n') + 1);
	if (new_buf == 0)
	{
		*m_status = GNL_M_ERROR;
		return (ft_free(&buf));
	}
	ft_free(&buf);
	return (new_buf);
}

static char	*ft_handle_read(int fd, char *buf)
{
	char	*str;
	int		rd_bytes;

	str = (char *)malloc(GNL_BUFFER_SIZE + 1);
	if (str == 0 && buf != 0)
		return (ft_free(&buf));
	if (str == 0)
		return (0);
	rd_bytes = 1;
	while (ft_strchr_gnl(buf, '\n') == 0 && rd_bytes > 0)
	{
		rd_bytes = read(fd, str, GNL_BUFFER_SIZE);
		if (rd_bytes < 0 && ft_free(&str) == 0 && buf != 0)
			return (ft_free(&buf));
		if (rd_bytes < 0)
			return (0);
		str[rd_bytes] = 0;
		buf = ft_strjoin_gnl(buf, str);
		if (buf == 0)
			return (ft_free(&str));
	}
	ft_free(&str);
	return (buf);
}

char	*get_next_line(int fd)
{
	char		status[1];
	char		*new_line;
	static char	*buf[GNL_MAX_FD + 1];

	if (fd < 0 || GNL_BUFFER_SIZE <= 0 || fd > GNL_MAX_FD)
		return (0);
	*status = GNL_NORMAL;
	buf[fd] = ft_handle_read(fd, buf[fd]);
	if (buf[fd] == 0)
		return (0);
	new_line = ft_strdup_gnl(buf[fd]);
	if (new_line == 0)
		return (ft_free(&buf[fd]));
	buf[fd] = ft_trim_head(buf[fd], status);
	if (*status == GNL_M_ERROR)
		return (ft_free(&new_line));
	new_line = ft_trim_tail(new_line, status);
	if (*status == GNL_M_ERROR)
		return (ft_free(&buf[fd]));
	return (new_line);
}
