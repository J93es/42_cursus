/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:46:59 by mijung            #+#    #+#             */
/*   Updated: 2022/07/09 11:48:01 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				cnt;
	unsigned char		ch;
	const unsigned char	*str;

	cnt = 0;
	ch = (unsigned char)c;
	str = (unsigned char *)s;
	while (cnt++ < n)
	{
		if (*str == ch)
			return ((void *)str);
		str++;
	}
	return (0);
}
