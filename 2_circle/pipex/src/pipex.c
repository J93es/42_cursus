#include "./pipex.h"

int	ft_free(int flag, char **strs, char *str)
{
	int	i;

	i = 0;
	if (strs != NULL)
	{
		while (strs[i] != NULL)
		{
			free(strs[i]);
			strs[i++] = NULL;
		}
		free(strs);
		strs = NULL;
	}
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (flag);
}

int	main(int argc, char **argv, char **envp)
{
	t_tools	tools;

	ft_preset(argc, argv, envp, &tools);
	ft_making(argv, envp, &tools);
	ft_free(EXIT_SUCCESS, tools.envp_path, NULL);
	exit(EXIT_SUCCESS);
}
