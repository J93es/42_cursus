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

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	i = 0;
	needle_len = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (*(needle + needle_len) != 0)
		needle_len++;
	while (*(haystack + i) != 0 && i + needle_len <= len)
	{
		j = 0;
		while (j < needle_len
			&& (*(haystack + i + j) != 0 || *(needle + j) != 0))
		{
			if (*(haystack + i + j) != *(needle + j))
				break ;
			j++;
		}
		if (j == needle_len)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
