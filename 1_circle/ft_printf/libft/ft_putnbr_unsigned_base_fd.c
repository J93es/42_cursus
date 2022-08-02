/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_base_fd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:29:35 by mijung            #+#    #+#             */
/*   Updated: 2022/08/02 13:30:11 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_unsigned_base_fd(unsigned int n, unsigned int base,
	int fd, char *base_str)
{
	if (fd < 0)
		return ;
	if (n == 0)
		write (fd, "0", 1);
	if (n > 0)
	{
		if (n / base > 0)
			ft_putnbr_unsigned_base_fd(n / base, base,
				fd, base_str);
		write(fd, &base_str[n % base], 1);
	}
}
