/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:54:44 by mijung            #+#    #+#             */
/*   Updated: 2022/07/09 11:55:22 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < n && (*(s1 + i) != 0 || *(s2 + i) != 0))
	{
		c1 = (unsigned char)*(s1 + i);
		c2 = (unsigned char)*(s2 + i);
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}
