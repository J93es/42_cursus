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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define GNL_BUFFER_SIZE 1024
# else
#  define GNL_BUFFER_SIZE BUFFER_SIZE
# endif

# ifndef GNL_STATUS
#  define GNL_STATUS
#  define GNL_NORMAL 0
#  define GNL_M_ERROR 1
# endif

# ifndef GNL_MAX_FD
#  if OPEN_MAX > 50000
#   define GNL_MAX_FD 50000
#  else
#   define GNL_MAX_FD OPEN_MAX
#  endif
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *s);
char	*ft_strdup_gnl(char *s1);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
#endif
