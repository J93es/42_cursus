/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:52:47 by mijung            #+#    #+#             */
/*   Updated: 2022/07/09 11:53:32 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = 0;
	dst_len = 0;
	while (*(src + src_len) != 0)
		src_len++;
	while (*(dst + dst_len) != 0)
		dst_len++;
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (*(src + i) != 0 && dstsize > dst_len + i + 1)
	{
		*(dst + dst_len + i) = *(src + i);
		i++;
	}
	*(dst + dst_len + i) = 0;
	return (src_len + dst_len);
}
