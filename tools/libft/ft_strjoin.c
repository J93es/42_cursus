/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:22:21 by mijung            #+#    #+#             */
/*   Updated: 2022/07/14 11:22:11 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	while (*(s1 + s1_len) != 0)
		s1_len++;
	while (*(s2 + s2_len) != 0)
		s2_len++;
	dst = (char *)malloc(s1_len + s2_len + 1);
	if (dst == 0)
		return (0);
	ptr = dst;
	while (s1_len-- > 0)
		*ptr++ = *s1++;
	while (s2_len-- > 0)
		*ptr++ = *s2++;
	*ptr = 0;
	return (dst);
}
