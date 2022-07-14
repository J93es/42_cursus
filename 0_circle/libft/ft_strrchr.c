/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:56:20 by mijung            #+#    #+#             */
/*   Updated: 2022/07/09 11:57:25 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*head;

	ch = (char)c;
	head = (char *)s;
	while (*s != 0)
		s++;
	while (s != head)
	{
		if (*s == ch)
			return ((char *)s);
		s--;
	}
	if (*s == ch)
		return ((char *)s);
	return (0);
}
