/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:52:01 by mijung            #+#    #+#             */
/*   Updated: 2022/07/11 15:52:40 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_totalsize(char const *s, char const c)
{
	size_t	i;
	size_t	total_str;

	i = 0;
	total_str = 0;
	while (*(s + i) != 0)
	{
		while (*(s + i) != 0 && *(s + i) == c)
			i++;
		if (*(s + i) != 0)
			total_str++;
		while (*(s + i) != 0 && *(s + i) != c)
			i++;
	}
	return (total_str);
}

static int	ft_strset(char **dst, char const *s, char c, size_t dst_strpos)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (*(s + size) != 0 && *(s + size) != c)
		size++;
	dst[dst_strpos] = (char *)malloc(size + 1);
	if (dst[dst_strpos] == 0)
	{
		i = 0;
		while (i < dst_strpos)
			free (dst[i] = 0);
		free(dst = 0);
		dst = 0;
		return (0);
	}
	while (*(s + i) != 0 && *(s + i) != c)
	{
		*(dst[dst_strpos] + i) = *(s + i);
		i++;
	}
	*(dst[dst_strpos] + i) = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	dst_strpos;

	if (s == 0)
		return (0);
	dst_strpos = 0;
	dst = (char **)malloc(sizeof(char *) * (ft_totalsize(s, c) + 1));
	if (dst == 0)
		return (0);
	while (*s != 0)
	{
		while (*s != 0 && *s == c)
			s++;
		if (*s != 0)
			if (ft_strset(dst, s, c, dst_strpos++) == 0)
				return (0);
		while (*s != 0 && *s != c)
			s++;
	}
	dst[dst_strpos] = 0;
	return (dst);
}
