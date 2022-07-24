/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:52:01 by mijung            #+#    #+#             */
/*   Updated: 2022/07/09 18:21:08 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dest;
	char	*ptr;

	s1_len = 0;
	while (*(s1 + s1_len) != 0)
		s1_len++;
	dest = (char *)malloc(s1_len + 1);
	if (dest == 0)
		return (0);
	ptr = dest;
	while (*s1 != 0)
		*ptr++ = *s1++;
	return (dest);
}
