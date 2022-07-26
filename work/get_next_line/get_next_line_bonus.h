#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <stddef.h>

# ifndef GNLB_STATUS
#  define GNLB_STATUS
#  define GNLB_NORMAL 0
#  define GNLB_M_ERROR 1
#  define GNLB_RD_ERROR 3
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
#endif