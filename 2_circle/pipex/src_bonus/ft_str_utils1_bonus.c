#include "./pipex_bonus.h"

void	ft_printf_error(const char *s, ...)
{
	va_list	ap;
	char	*temp;

	va_start(ap, s);
	while (*s != 0)
	{
		if (*s++ == '%')
		{
			if (*s == 's')
			{
				temp = va_arg(ap, char *);
				write(2, temp, ft_strlen(temp));
				s++;
			}
		}
		else
			write (2, s - 1, 1);
	}
	va_end(ap);
}

char	*ft_strdup(char *s1)
{
	size_t	s1_len;
	char	*dest;
	char	*ptr;

	s1_len = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[s1_len] != 0)
		s1_len++;
	dest = (char *)malloc(s1_len + 1);
	if (dest == NULL)
		return (NULL);
	ptr = dest;
	while (*s1 != 0)
		*ptr++ = *s1++;
	*ptr = 0;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	char	*ptr;
	char	*temp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (dst == NULL)
		return (NULL);
	ptr = dst;
	temp = s1;
	while (*temp != 0)
		*ptr++ = *temp++;
	while (*s2 != 0)
		*ptr++ = *s2++;
	*ptr = 0;
	return (dst);
}
