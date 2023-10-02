#include <stdlib.h>

static size_t	ft_totalsize(char const *s, char const c)
{
	size_t	i;
	size_t	total_str;

	i = 0;
	total_str = 0;
	while (*(s + i) != 0)
	{
		while (*(s + i) != 0 && *(s + i) == c)
			i++;
		if (*(s + i) != 0)
			total_str++;
		while (*(s + i) != 0 && *(s + i) != c)
			i++;
	}
	return (total_str);
}

static void	ft_strset(char **dst, char const *s, char c, size_t dst_strpos)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (*(s + size) != 0 && *(s + size) != c)
		size++;
	dst[dst_strpos] = (char *)malloc(size + 1);
	if (dst[dst_strpos] == 0)
		exit(-1);
	while (*(s + i) != 0 && *(s + i) != c)
	{
		*(dst[dst_strpos] + i) = *(s + i);
		i++;
	}
	*(dst[dst_strpos] + i) = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	dst_strpos;

	dst = 0;
	dst_strpos = 0;
	if (s == 0)
		return (0);
	dst = (char **)malloc(sizeof(char *) * (ft_totalsize(s, c) + 1));
	if (dst == 0)
		return (0);
	while (*s != 0)
	{
		while (*s != 0 && *s == c)
			s++;
		if (*s != 0)
			ft_strset(dst, s, c, dst_strpos++);
		while (*s != 0 && *s != c)
			s++;
	}
	dst[dst_strpos] = 0;
	return (dst);
}
