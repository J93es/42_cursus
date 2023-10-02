#include "./so_long.h"

char	*ft_strdup(char *s1)
{
	size_t	s1_len;
	char	*dest;
	char	*ptr;

	s1_len = 0;
	if (s1 == 0)
		return (0);
	while (s1[s1_len] != 0)
		s1_len++;
	dest = (char *)malloc(s1_len + 1);
	if (dest == 0)
		return (0);
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

	if (s1 == 0)
		s1 = ft_strdup("\0");
	if (s2 == 0)
		s2 = ft_strdup("\0");
	if (s1 == 0 || s2 == 0)
		return (0);
	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (dst == 0)
		return (0);
	ptr = dst;
	temp = s1;
	while (*temp != 0)
		*ptr++ = *temp++;
	while (*s2 != 0)
		*ptr++ = *s2++;
	*ptr = 0;
	return (dst);
}

int	ft_finddigit(int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		digit++;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	int		digit;
	long	num;
	char	*str;

	digit = ft_finddigit(n);
	num = (long)n;
	str = (char *)malloc(digit + 1);
	if (str == 0)
		return (0);
	if (n == 0)
		*str = '0';
	if (n < 0)
	{
		num *= -1;
		*str = '-';
	}
	*(str + digit--) = 0;
	while (num > 0)
	{
		*(str + digit--) = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
