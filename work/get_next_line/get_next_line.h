#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef GNL_FREE_FLAG
#  define GNL_FREE_FLAG

#  define SINGLE_FREE 0
#  define FINISH_FREE 1
#  define ERROR_FREE 2
# endif


# ifndef GNL_PTR_FREE
#  define GNL_PTR_FREE

#  define BUF_PTR 0
#  define NEW_LINE_PTR 1
#  define STR_PTR 2
#  define PTR_FREE_LEN 3
# endif


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char	*get_next_line(int fd);
void	ft_gnl_strlcpy(char *dst, char *src, long dstsize);
char	*ft_gnl_strdup(const char *s1);
char	*ft_gnl_strchr(char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
#endif