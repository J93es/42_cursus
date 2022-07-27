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

static int	ft_finddigit(int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		digit++;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		digit;
	long	num;
	char	dst[21];

	if (fd < 0)
		return ;
	digit = ft_finddigit(n);
	num = (long)n;
	if (n == 0)
		*dst = '0';
	if (n < 0)
	{
		num *= -1;
		*dst = '-';
	}
	*(dst + digit--) = 0;
	while (num > 0)
	{
		*(dst + digit--) = num % 10 + '0';
		num /= 10;
	}
	digit = 0;
	while (*(dst + digit) != 0)
		if (write(fd, dst + digit++, 1) == 0)
			write(fd, dst + digit - 1, 1);
}
