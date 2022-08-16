/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:53:31 by mijung            #+#    #+#             */
/*   Updated: 2022/07/11 15:53:33 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	num;

	num = (long)n;
	if (fd < 0)
		return ;
	if (num == 0)
		write (1, "0", fd);
	if (num < 0)
	{
		num *= -1;
		write (1, "-", fd);
	}
	if (num > 0)
	{
		if (num / 10 > 0)
			ft_putnbr_fd((int)(num / 10), fd);
		c = num % 10 + '0';
		write(1, &c, fd);
	}
}