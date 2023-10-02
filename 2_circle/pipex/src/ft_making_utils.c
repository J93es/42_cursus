#include "./pipex.h"

void	ft_check_file(t_tools *tools)
{
	if (tools->flag_check_file != FTTRUE)
		return ;
	if (access(tools->output_file_name, F_OK) == 0
		&& access(tools->output_file_name, W_OK) != 0)
		ft_printf_error("pipex: permission denied: %s\n", \
			tools->output_file_name);
	else if (tools->output_file == -1)
		ft_printf_error("pipex: file open failed: %s", tools->output_file_name);
	else
		return ;
	exit(ft_free(EXIT_FAILURE, tools->envp_path, NULL));
}

void	ft_reading_empty(t_tools *tools)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(ft_free(FTERROR, tools->envp_path, NULL));
	pid = fork();
	if (pid == -1)
		exit(ft_free(FTERROR, tools->envp_path, NULL));
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		write(fd[1], "", 0);
		exit(ft_free(EXIT_FAILURE, tools->envp_path, NULL));
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
		close(fd[0]);
	}
}
