/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:17:18 by mijung            #+#    #+#             */
/*   Updated: 2022/07/27 12:17:28 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	size_t	s1_len;
	char	*dest;
	char	*ptr;

	s1_len = 0;
	if (s1 == 0)
		return (0);
	while (s1[s1_len] != 0)
		s1_len++;
	dest = (char *)malloc(s1_len + 1);
	if (dest == 0)
		return (0);
	ptr = dest;
	while (*s1 != 0)
		*ptr++ = *s1++;
	*ptr = 0;
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	if (s == 0)
		return (0);
	while (*s != 0)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	char	*ptr;
	char	*temp;

	if (s1 == 0)
		s1 = ft_strdup("\0");
	if (s1 == 0 || s2 == 0)
		return (s1);
	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (dst == 0)
		return (0);
	ptr = dst;
	temp = s1;
	while (*temp != 0)
		*ptr++ = *temp++;
	while (*s2 != 0)
		*ptr++ = *s2++;
	*ptr = 0;
	free(s1);
	s1 = 0;
	return (dst);
}
