#include "./pipex_bonus.h"

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

	if (argc < 5)
	{
		ft_printf_error("pipex: bad argument\n");
		ft_printf_error("usage: ./pipex [file_in]                   ");
		ft_printf_error("\"cmd1\" ... \"cmdn\" [file_out]\n");
		ft_printf_error("       ./pipex \"here_doc\" \"LIMITER_STRING\" ");
		ft_printf_error("\"cmd1\" ... \"cmdn\" [file_out]\n");
		exit (EXIT_FAILURE);
	}
	ft_preset(argc, argv, envp, &tools);
	ft_making(argc, argv, envp, &tools);
	ft_free(EXIT_SUCCESS, tools.envp_path, NULL);
	exit(EXIT_SUCCESS);
}
