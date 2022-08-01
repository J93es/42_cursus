#include <unistd.h>

void	ft_putnbr_unsigned_base_fd(unsigned long n, unsigned long base,
	int fd)
{
	char	c;

	if (fd < 0)
		return ;
	if (n == 0)
		write (1, "0", fd);
	if (n > 0)
	{
		if (n / base > 0)
			ft_putnbr_unsigned_base_fd(n / base, base, fd);
		c = "0123456789abcdef"[n % base];
		write(1, &c, fd);
	}
}
