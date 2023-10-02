#include "./pipex_bonus.h"

static void	ft_check_files(int argc, char **argv, t_tools *tools)
{
	char	temp[1];

	if (tools->flag_hd == FTFALSE)
		tools->input_file = open(argv[1], O_RDONLY);
	if (tools->flag_hd == FTFALSE && access(argv[1], F_OK) != 0)
		ft_printf_error("pipex: no such file or directory: %s\n", argv[1]);
	else if (tools->flag_hd == FTFALSE && access(argv[1], R_OK) != 0)
		ft_printf_error("pipex: permission denied: %s\n", argv[1]);
	else if (tools->flag_hd == FTTRUE && read(0, temp, 0) < 0)
		ft_printf_error("pipex: here_doc read failed\n");
	else if (tools->input_file == -1)
		ft_printf_error("pipex: file open failed: %s", tools->output_file_name);
	if (tools->flag_hd == FTTRUE)
		tools->output_file = \
			open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (tools->flag_hd == FTFALSE)
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
	tools->flag_hd = FTFALSE;
	tools->limiter = NULL;
	tools->cmd_start_index = 2;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (argc < 6)
		{
			ft_printf_error("pipex: bad argument\n");
			ft_printf_error("usage: ./pipex [file_in]                   ");
			ft_printf_error("\"cmd1\" ... \"cmdn\" [file_out]\n");
			ft_printf_error("       ./pipex \"here_doc\" \"LIMITER_STRING\" ");
			ft_printf_error("\"cmd1\" ... \"cmdn\" [file_out]\n");
			exit(EXIT_FAILURE);
		}
		tools->flag_hd = FTTRUE;
		tools->limiter = argv[2];
		tools->cmd_start_index = 3;
	}
	ft_check_files(argc, argv, tools);
	ft_make_envp_path(envp, tools);
}
