/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:52:01 by mijung            #+#    #+#             */
/*   Updated: 2022/07/27 14:49:32 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dst;
	char	*ptr;
	char	*s1_temp;

	s1_len = 0;
	s1_temp = (char *)s1;
	while (*(s1_temp + s1_len) != 0)
		s1_len++;
	dst = (char *)malloc(s1_len + 1);
	if (dst == 0)
		return (0);
	ptr = dst;
	while (*s1_temp != 0)
		*ptr++ = *s1_temp++;
	*ptr = 0;
	return (dst);
}
