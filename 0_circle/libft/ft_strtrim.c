/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:50:37 by mijung            #+#    #+#             */
/*   Updated: 2022/07/12 13:13:43 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_isinstr(char c, char const *str)
{
	while (*str != 0)
		if (*str++ == c)
			return (1);
	return (0);
}

static long	ft_findsize(char const *s1, char const *set)
{
	char	head;
	size_t	size;

	head = *s1;
	size = ft_strlen(s1);
	s1 += size - 1;
	while (*s1 != head && ft_isinstr(*s1, set) != 0)
	{
		s1--;
		size--;
	}
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	size;

	dst = 0;
	size = 0;
	if (s1 == 0 || set == 0)
		return (0);
	while (ft_isinstr(*s1, set) != 0)
		s1++;
	if (*s1 == 0)
		return (ft_calloc(1, 1));
	size = ft_findsize(s1, set);
	dst = (char *)malloc(size + 1);
	if (dst == 0)
		return (0);
	ft_strlcpy(dst, s1, size + 1);
	return (dst);
}
