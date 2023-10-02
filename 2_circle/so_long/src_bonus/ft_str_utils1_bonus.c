#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*head;

	ch = (char)c;
	head = (char *)s;
	while (*s != 0)
		s++;
	while (s != head)
	{
		if (*s == ch)
			return ((char *)s);
		s--;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}

int	ft_printfd(int fd, const char *s, ...)
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
				write(fd, temp, ft_strlen(temp));
				s++;
			}
		}
		else
			write (fd, s - 1, 1);
	}
	va_end(ap);
	return (1);
}
