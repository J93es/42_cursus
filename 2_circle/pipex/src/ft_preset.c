#include "./pipex.h"

static void	ft_open_files(int argc, char **argv, t_tools *tools)
{
	tools->input_file = open(argv[1], O_RDONLY);
	if (access(argv[1], F_OK) != 0)
		ft_printf_error("pipex: no such file or directory: %s\n", argv[1]);
	else if (access(argv[1], F_OK) == 0 && access(argv[1], R_OK) != 0)
		ft_printf_error("pipex: permission denied: %s\n", argv[1]);
	else if (tools->input_file == -1)
		ft_printf_error("pipex: file open failed %s", argv[1]);
	tools->output_file = \
		open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	tools->output_file_name = argv[argc - 1];
}

static void	ft_make_envp_path(char **envp, t_tools *tools)
{
	int	i;

	i = 0;
	while (envp[i] != 0 && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (envp[i] == 0)
		tools->envp_path = NULL;
	else
	{
		tools->envp_path = ft_split(envp[i] + 5, ':');
		if (tools->envp_path == NULL)
			exit(FTERROR);
	}
}

void	ft_preset(int argc, char **argv, char **envp, t_tools *tools)
{
	if (argc != 5)
	{
		ft_printf_error("pipex: bad argument\n");
		ft_printf_error("usage: ./pipex [file_in] \"cmd1\" \"cmd2\" [file_out]\n");
		exit(EXIT_FAILURE);
	}
	ft_open_files(argc, argv, tools);
	ft_make_envp_path(envp, tools);
}
