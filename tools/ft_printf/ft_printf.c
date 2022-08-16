/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:33:21 by mijung            #+#    #+#             */
/*   Updated: 2022/08/02 13:33:23 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	ft_printf_isflag(char ch)
{
	if (ch == '%')
		return (FTPF_PERCSIG);
	if (ch == 's' || ch == 'p')
		return (FTPF_FLAG_PTR);
	if (ch == 'c' || ch == 'd' || ch == 'i'
		|| ch == 'u' || ch == 'x' || ch == 'X')
		return (FTPF_FLAG_VAR);
	return (FTPF_FLAG_OTHER);
}

static void	ft_printf_ptr(char flag, void *ptr, int *len)
{
	if (flag == 's')
	{
		if (ptr == 0)
			ft_printfstr("(null)", len);
		else
			ft_printfstr((char *)ptr, len);
	}
	if (flag == 'p')
	{
		ft_printfstr("0x", len);
		ft_printfnbr_unsigned_base((unsigned long)ptr, 16,
			"0123456789abcdef", len);
	}
}

static void	ft_printf_var(char flag, long long cn, int *len)
{
	if (flag == 'c')
		ft_printfchar((char)cn, len);
	if (flag == 'd' || flag == 'i')
		ft_printfnbr_base((int)cn, 10, "0123456789", len);
	if (flag == 'u')
		ft_printfnbr_unsigned_base((unsigned int)cn, 10,
			"0123456789", len);
	if (flag == 'x')
		ft_printfnbr_unsigned_base((unsigned int)cn, 16,
			"0123456789abcdef", len);
	if (flag == 'X')
		ft_printfnbr_unsigned_base((unsigned int)cn, 16,
			"0123456789ABCDEF", len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, s);
	while (*s != 0)
	{
		if (ft_printf_isflag(*s++) == FTPF_PERCSIG)
		{
			if (ft_printf_isflag(*s) == FTPF_PERCSIG)
				ft_printfchar(*s++, &len);
			else if (ft_printf_isflag(*s) == FTPF_FLAG_PTR)
				ft_printf_ptr(*s++, va_arg(ap, void *), &len);
			else if (ft_printf_isflag(*s) == FTPF_FLAG_VAR)
				ft_printf_var(*s++, va_arg(ap, long long), &len);
			else
				return (FTPF_ERROR);
		}
		else
			ft_printfchar(*(s - 1), &len);
	}
	va_end(ap);
	return (len);
}
