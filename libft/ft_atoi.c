/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:17:18 by mijung            #+#    #+#             */
/*   Updated: 2022/07/14 11:19:31 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				n;
	long			p;
	unsigned long	num;

	n = 0;
	p = 1;
	num = 0;
	while (*str != 0 && (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			p = -1;
	while (*str == '0')
		str++;
	while ('0' <= *(str + n) && *(str + n) <= '9')
	{
		num = 10 * num + *(str + n++) - '0';
		if (n > 18 && p > 0 && ft_strncmp(str, "9223372036854775807", 19) > 0)
			return (-1);
		if (n > 18 && p < 0 && ft_strncmp(str, "9223372036854775808", 19) > 0)
			return (0);
	}
	return ((int)p * (int)num);
}
