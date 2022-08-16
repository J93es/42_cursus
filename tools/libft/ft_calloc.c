/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:42:15 by mijung            #+#    #+#             */
/*   Updated: 2022/07/09 14:40:59 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*b;
	size_t			len;
	unsigned char	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	len = count * size;
	if (len / count != size || len % size != 0)
		return (0);
	b = (void *)malloc(len);
	if (b == 0)
		return (0);
	ptr = (unsigned char *)b;
	while (len-- > 0)
		*ptr++ = 0;
	return (b);
}
