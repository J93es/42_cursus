/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:17:47 by mijung            #+#    #+#             */
/*   Updated: 2022/07/27 12:23:56 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <limits.h>

# ifndef GNLB_STATUS
#  define GNLB_STATUS
#  define GNLB_NORMAL 0
#  define GNLB_M_ERROR 1
# endif

# ifndef GNLB_MAX_FD
#  if OPEN_MAX > 50000
#   define GNLB_MAX_FD 50000
#  else
#   define GNLB_MAX_FD OPEN_MAX
#  endif
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
#endif
