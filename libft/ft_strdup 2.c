/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:52:01 by mijung            #+#    #+#             */
/*   Updated: 2022/07/09 18:21:08 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dest;

	s1_len = ft_strlen(s1);
	dest = (char *)malloc(s1_len + 1);
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, s1, s1_len + 1);
	return (dest);
}
