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

static int	ft_custom_return(unsigned long num,
		long plma, const char *str, int cnt)
{
	if (cnt > 18)
	{
		if (plma == 1 && ft_strncmp(str, "9223372036854775807", 20) > 0)
			return (-1);
		if (plma == -1 && ft_strncmp(str, "-9223372036854775808", 21) > 0)
			return (0);
	}
	return ((int)num * (int)plma);
}

int	ft_atoi(const char *str)
{
	int				cnt;
	long			plma;
	unsigned long	num;

	cnt = 0;
	plma = 1;
	num = 0;
	while (*str != 0 && (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			plma = -1;
	while (*str == '0')
		str++;
	while (*str != 0 && '0' <= *str && *str <= '9')
	{
		num = 10 * num + *str++ - '0';
		if (cnt > 18)
			break ;
		cnt++;
	}
	return (ft_custom_return(num, plma, str, cnt));
}
