/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:54:22 by mijung            #+#    #+#             */
/*   Updated: 2022/07/11 15:54:58 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_itoa(int n)
{
	int		digit;
	long	num;
	char	*str;

	digit = ft_finddigit(n);
	num = (long)n;
	str = (char *)malloc(digit + 1);
	if (str == 0)
		return (0);
	if (n == 0)
		*str = '0';
	if (n < 0)
	{
		num *= -1;
		*str = '-';
	}
	*(str + digit--) = 0;
	while (num > 0)
	{
		*(str + digit--) = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
