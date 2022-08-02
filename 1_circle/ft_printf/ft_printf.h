/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:33:12 by mijung            #+#    #+#             */
/*   Updated: 2022/08/02 13:33:14 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef FTPF_FT_PRINTF
#  define FTPF_FT_PRINTF

#  define FTPF_ERROR -1
#  define FTPF_PERCSIG 0
#  define FTPF_FLAG_PTR 1
#  define FTPF_FLAG_VAR 2
#  define FTPF_FLAG_OTHER 3
# endif

int		ft_printf(const char *s, ...);
void	ft_printfchar(char c, int *len);
void	ft_printfstr(char *s, int *len);
void	ft_printfnbr_base(int n, unsigned int base, char *str_base, int *len);
void	ft_printfnbr_unsigned_base(unsigned long n, unsigned long base,
			char *str_base, int *len);
#endif
