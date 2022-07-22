/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:55:23 by mijung            #+#    #+#             */
/*   Updated: 2022/07/09 11:56:17 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	haystack_len;
	size_t	needle_len;

	i = 0;
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);
	if (len > haystack_len)
		len = haystack_len;
	while (i + needle_len <= len)
	{
		if (ft_strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
