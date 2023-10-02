#include "./pipex.h"

static char	*ft_make_relative_pathname(char **pathname_opt, t_tools *tools)
{
	char	*pathname;

	pathname = ft_strdup(pathname_opt[0]);
	if (pathname == NULL)
		exit(FTERROR);
	if (access(pathname_opt[0], F_OK) != 0)
	{
		ft_printf_error("pipex: command not found: %s\n", pathname_opt[0]);
		ft_check_file(tools);
		ft_free(127, pathname_opt, NULL);
		exit(ft_free(127, tools->envp_path, NULL));
	}
	else if (access(pathname_opt[0], X_OK) != 0)
	{
		ft_printf_error("pipex: permission denied: %s\n", pathname_opt[0]);
		ft_check_file(tools);
		ft_free(126, pathname_opt, NULL);
		exit(ft_free(126, tools->envp_path, NULL));
	}
	ft_check_file(tools);
	return (pathname);
}

static char	*ft_make_absolute_pathname(char **pathname_opt, t_tools *tools)
{
	int		i;
	char	*temp;
	char	*pathname;

	i = -1;
	while ((tools->envp_path)[++i] != NULL)
	{
		temp = ft_strjoin((tools->envp_path)[i], "/");
		if (temp == NULL)
			exit(ft_free(FTERROR, tools->envp_path, NULL));
		pathname = ft_strjoin(temp, pathname_opt[0]);
		ft_free(EXIT_SUCCESS, NULL, temp);
		if (pathname == NULL)
			exit(ft_free(FTERROR, tools->envp_path, NULL));
		if (access(pathname, F_OK) == 0)
		{
			ft_check_file(tools);
			return (pathname);
		}
		ft_free(EXIT_SUCCESS, NULL, pathname);
	}
	ft_printf_error("pipex: command not found: %s\n", pathname_opt[0]);
	ft_check_file(tools);
	ft_free(127, pathname_opt, NULL);
	exit(ft_free(127, tools->envp_path, NULL));
}

static void	ft_output(char *pathnameopt, char **envp, t_tools *tools)
{
	char	**pathname_opt;
	char	*pathname;

	pathname_opt = ft_makepathname_opt(pathnameopt);
	if (pathname_opt == NULL)
		exit(ft_free(FTERROR, tools->envp_path, NULL));
	if (ft_strrchr(pathname_opt[0], '/') == NULL || tools->envp_path == NULL)
		pathname = ft_make_absolute_pathname(pathname_opt, tools);
	else
		pathname = ft_make_relative_pathname(pathname_opt, tools);
	if (execve(pathname, pathname_opt, envp) == -1)
	{
		ft_printf_error("pipex: execve failed\n");
		ft_free(EXIT_FAILURE, pathname_opt, pathname);
		exit(ft_free(EXIT_FAILURE, tools->envp_path, NULL));
	}
}

static void	ft_cmding(char *pathnameopt, char **envp, t_tools *tools)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(ft_free(FTERROR, tools->envp_path, NULL));
	pid = fork();
	if (pid == -1)
		exit(ft_free(FTERROR, tools->envp_path, NULL));
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_output(pathnameopt, envp, tools);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, WNOHANG);
		close(fd[0]);
	}
}

void	ft_making(char **argv, char **envp, t_tools *tools)
{
	tools->flag_check_file = FTFALSE;
	if (tools->input_file == -1)
		ft_reading_empty(tools);
	else
		dup2(tools->input_file, STDIN_FILENO);
	ft_cmding(argv[2], envp, tools);
	tools->flag_check_file = FTTRUE;
	dup2(tools->output_file, STDOUT_FILENO);
	ft_output(argv[3], envp, tools);
}
