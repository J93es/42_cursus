/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:50:38 by mijung            #+#    #+#             */
/*   Updated: 2022/07/09 11:51:10 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	unsigned char	*ptr;

	ch = (unsigned char)c;
	ptr = (unsigned char *)b;
	while (len-- > 0)
		*ptr++ = ch;
	return (b);
}
