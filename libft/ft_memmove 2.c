/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:49:32 by mijung            #+#    #+#             */
/*   Updated: 2022/07/09 12:56:08 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstaddr;
	char	*srcaddr;

	dstaddr = (char *)dst;
	srcaddr = (char *)src;
	if (dstaddr == srcaddr)
		return (dst);
	else if (dst < src)
		while (len-- > 0)
			*dstaddr++ = *srcaddr++;
	else
	{
		dstaddr += len - 1;
		srcaddr += len - 1;
		while (len-- > 0)
			*dstaddr-- = *srcaddr--;
	}
	return (dst);
}
