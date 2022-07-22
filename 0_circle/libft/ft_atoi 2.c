/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:40:22 by mijung            #+#    #+#             */
/*   Updated: 2022/07/11 15:49:49 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_flow(char ch, long plma, char *possible_flow, int cnt)
{
	if (cnt > 18)
	{
		*possible_flow = 1;
		return (0);
	}
	if (plma == 1)
	{
		if (ch > "9223372036854775807"[cnt] && *possible_flow == 0)
			*possible_flow = 1;
		else if (ch < "9223372036854775807"[cnt] && *possible_flow == 0)
			*possible_flow = -1;
	}
	if (plma == -1)
	{
		if (ch > "9223372036854775808"[cnt] && *possible_flow == 0)
			*possible_flow = 1;
		else if (ch < "9223372036854775808"[cnt] && *possible_flow == 0)
			*possible_flow = -1;
	}
	return (1);
}

static int	ft_custom_return(unsigned long num,
		long plma, char possible_flow, int cnt)
{
	if (possible_flow == 1 && cnt >= 18)
	{
		if (plma == -1)
			return (0);
		else
			return (-1);
	}
	return ((int)num * (int)plma);
}

int	ft_atoi(const char *str)
{
	int				cnt;
	char			possible_flow;
	long			plma;
	unsigned long	num;

	cnt = 0;
	possible_flow = 0;
	plma = 1;
	num = 0;
	while (*str != 0 && (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			plma = -1;
	while (*str != 0 && *str == '0')
		str++;
	while (*str != 0 && '0' <= *str && *str <= '9')
	{
		num = 10 * num + *str - '0';
		if (ft_check_flow(*str++, plma, &possible_flow, cnt++) == 0)
			break ;
	}
	return (ft_custom_return(num, plma, possible_flow, cnt));
}
