/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:53:46 by mijung            #+#    #+#             */
/*   Updated: 2022/07/11 15:53:48 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	if (s == 0 || fd < 0)
		return ;
	while (*(s + len) != 0)
		len++;
	if (s != 0)
		write(fd, s, len);
	write(fd, "\n", 1);
}
