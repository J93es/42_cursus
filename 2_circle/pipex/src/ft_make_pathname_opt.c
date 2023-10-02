#include "./pipex.h"

static size_t	ft_strsize(char *s)
{
	char	*ptr;
	size_t	len;

	len = 0;
	ptr = NULL;
	if (*s == '\'')
	{
		if (*(s + 1) != 0)
			ptr = ft_strchr(s + 1, '\'');
		if (ptr == NULL)
			len = 1;
		else
		{
			while (*(s + 1 + len) != 0 && *(s + 1 + len) != '\'')
				len++;
			len += 2;
		}
	}
	else
	{
		while (*(s + len) != 0 && *(s + len) != ' ')
			len++;
	}
	return (len);
}

static size_t	ft_totalsize(char *s)
{
	size_t	total_str;

	total_str = 0;
	while (*s != 0)
	{
		while (*s != 0 && *s == ' ')
			s++;
		total_str++;
		s += ft_strsize(s);
	}
	return (total_str);
}

static int	ft_strset(char **dst, char *s, size_t dst_strpos)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = NULL;
	dst[dst_strpos] = malloc(sizeof(char) * (ft_strsize(s) + 1));
	if (dst[dst_strpos] == NULL)
		return (1);
	if (*s == '\'')
	{
		if (*(s + 1) != 0)
			ptr = ft_strchr(s + 1, '\'');
		if (ptr == NULL)
			dst[dst_strpos][i++] = '\'';
		else
			while (*(s + 1) != 0 && *(s + 1) != '\'')
				dst[dst_strpos][i++] = *(++s);
	}
	else
	{
		while (*s != 0 && *s != ' ')
			dst[dst_strpos][i++] = *s++;
	}
	dst[dst_strpos][i] = 0;
	return (0);
}

char	**ft_makepathname_opt(char *s)
{
	char	**dst;
	size_t	dst_strpos;

	dst_strpos = 0;
	if (s == NULL)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (ft_totalsize(s) + 1));
	if (dst == NULL)
		return (NULL);
	while (*s != 0)
	{
		while (*s != 0 && *s == ' ')
			s++;
		if (*s != 0)
			if (ft_strset(dst, s, dst_strpos++) != 0)
				return (NULL);
		s += ft_strsize(s);
	}
	dst[dst_strpos] = NULL;
	return (dst);
}
