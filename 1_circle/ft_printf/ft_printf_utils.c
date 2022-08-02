/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:33:56 by mijung            #+#    #+#             */
/*   Updated: 2022/08/02 13:33:57 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printfchar(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	ft_printfstr(char *s, int *len)
{
	if (s == 0)
		return ;
	while (*s != 0)
		*len += write(1, s++, 1);
}

void	ft_printfnbr_base(int n, unsigned int base, char *str_base, int *len)
{
	unsigned int	num;

	num = (unsigned int)n;
	if (n == 0)
		*len += write (1, "0", 1);
	if (n < 0)
	{
		num = (unsigned int)(-1 * n);
		*len += write (1, "-", 1);
	}
	if (num > 0)
	{
		if (num / base > 0)
			ft_printfnbr_base((int)(num / base), base, str_base, len);
		*len += write(1, &str_base[num % base], 1);
	}
}

void	ft_printfnbr_unsigned_base(unsigned long n, unsigned long base,
			char *str_base, int *len)
{
	if (n == 0)
		*len += write (1, "0", 1);
	if (n > 0)
	{
		if (n / base > 0)
			ft_printfnbr_unsigned_base(n / base, base, str_base, len);
		*len += write(1, &str_base[n % base], 1);
	}
}
