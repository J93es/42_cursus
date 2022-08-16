/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:48:55 by mijung            #+#    #+#             */
/*   Updated: 2022/07/09 11:49:29 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dstaddr;
	char	*srcaddr;

	dstaddr = (char *)dst;
	srcaddr = (char *)src;
	if (dstaddr == srcaddr)
		return (dst);
	while (n-- > 0)
		*dstaddr++ = *srcaddr++;
	return (dst);
}
