#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_tools	tools;

	if (argc == 1)
		return (FTNORMAL);
	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != 0 && ft_iswhat(argv[i][j], NULL) != FTDIGIT)
			j++;
		if (argv[i][j] == 0)
		{
			write(1, "Error\n", 7);
			return (1);
		}
	}
	ft_preset(&tools, argc, argv);
	if (tools.len > 5)
		ft_binary_rsort(&tools, FT_WRITE);
	else
		ft_onlyn_sortx(&tools, tools.len, FT_WRITE, AC_XA);
	ft_lstwrite(tools.w_lst);
	return (ft_free(&tools, FTNORMAL));
}
