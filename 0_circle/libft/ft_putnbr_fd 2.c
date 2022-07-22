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

#include "libft.h"

static int	ft_finddigit(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_custom(char *dst, int n)
{
	int		digit;
	long	num;

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
	return (dst);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	dst[21];

	i = 0;
	while (i < 21)
		dst[i++] = 0;
	ft_putstr_fd(ft_itoa_custom(dst, n), fd);
}
