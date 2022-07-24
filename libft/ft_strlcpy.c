/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:53:34 by mijung            #+#    #+#             */
/*   Updated: 2022/07/09 11:54:10 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*(src + i) != '\0' && i + 1 < dstsize)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (dstsize > 0)
		*(dst + i) = 0;
	i = 0;
	while (*(src + i) != 0)
		i++;
	return (i);
}
