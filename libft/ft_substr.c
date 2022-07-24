/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:26:46 by mijung            #+#    #+#             */
/*   Updated: 2022/07/09 18:20:11 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*dst;

	i = 0;
	s_len = 0;
	if (s == 0)
		return (0);
	while (*(s + s_len) != 0)
		s_len++;
	if (len > s_len)
		len = s_len;
	dst = (char *)malloc(len + 1);
	if (dst == 0)
		return (0);
	if (start > s_len)
	{
		*dst = 0;
		return (dst);
	}
	while (i < len)
		*(dst + i++) = *(s + start++);
	*(dst + i) = 0;
	return (dst);
}
