/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:46:05 by mijung            #+#    #+#             */
/*   Updated: 2022/07/12 13:08:56 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*dstaddr;
	unsigned char	*srcaddr;

	ch = (unsigned char)c;
	dstaddr = (unsigned char *)dst;
	srcaddr = (unsigned char *)src;
	while (n-- > 0)
	{
		*dstaddr = *srcaddr++;
		if (*dstaddr++ == ch)
			return ((void *)dstaddr);
	}
	return (0);
}
