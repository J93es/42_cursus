#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (*(s + len) != 0)
		len++;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return (1);
	while (i < n && (*(s1 + i) != 0 || *(s2 + i) != 0))
	{
		c1 = (unsigned char)*(s1 + i);
		c2 = (unsigned char)*(s2 + i);
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	if (s == 0)
		return (0);
	while (*s != 0)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (0);
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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	i = 0;
	needle_len = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (*(needle + needle_len) != 0)
		needle_len++;
	while (*(haystack + i) != 0 && i + needle_len <= len)
	{
		j = 0;
		while (j < needle_len
			&& (*(haystack + i + j) != 0 || *(needle + j) != 0))
		{
			if (*(haystack + i + j) != *(needle + j))
				break ;
			j++;
		}
		if (j == needle_len)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
