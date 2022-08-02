/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:26:33 by mijung            #+#    #+#             */
/*   Updated: 2022/08/02 13:30:38 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base_fd(int n, unsigned int base, int fd, char *base_str)
{
	unsigned int	num;

	if (fd < 0)
		return ;
	if (n == 0)
		write (fd, "0", 1);
	if (n < 0)
	{
		num = (unsigned int)(-1 * n);
		write (fd, "-", 1);
	}
	else
		num = (unsigned int)n;
	if (num > 0)
	{
		if (num / base > 0)
			ft_putnbr_base_fd((int)(num / base), base,
				fd, base_str);
		write(fd, &base_str[num % base], 1);
	}
}
