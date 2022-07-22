/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:51:12 by mijung            #+#    #+#             */
/*   Updated: 2022/07/11 15:51:18 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s == 0)
		return (0);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (str == 0)
		return (0);
	while (*(s + i) != 0)
	{
		*(str + i) = f(i, *(s + i));
		i++;
	}
	*(str + i) = 0;
	return (str);
}
