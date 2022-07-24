/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:50:37 by mijung            #+#    #+#             */
/*   Updated: 2022/07/14 11:13:42 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(set + i) != 0)
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	i;
	size_t	head_index;
	size_t	tail_index;

	i = 0;
	head_index = 0;
	tail_index = 0;
	while (*(s1 + head_index) != 0 && ft_char_in_set(*(s1 + head_index), set) == 1)
		head_index++;
	while (*(s1 + tail_index) != 0)
		tail_index++;
	while (tail_index > head_index && ft_char_in_set(*(s1 + tail_index - 1), set) == 1)
		tail_index--;
	dst = (char*)malloc(sizeof(*s1) * (tail_index - head_index + 1));
	if (dst == 0)
		return (0);
	while (head_index < tail_index)
		*(dst + i++) = *(s1 + head_index++);
	*(dst + i) = 0;
	return (dst);
}