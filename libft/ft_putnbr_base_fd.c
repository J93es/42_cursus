#include <unistd.h>

void	ft_putnbr_base_fd(int n, unsigned int base, int fd)
{
	char			c;
	unsigned int	num;

	num = (unsigned int)n;
	if (fd < 0)
		return ;
	if (n == 0)
		write (1, "0", fd);
	if (n < 0)
	{
		num = (unsigned int)(-1 * n);
		write (1, "-", fd);
	}
	if (num > 0)
	{
		if (num / base > 0)
			ft_putnbr_base_fd((int)(num / base), base, fd);
		c = "0123456789abcdef"[num % base];
		write(1, &c, fd);
	}
}
