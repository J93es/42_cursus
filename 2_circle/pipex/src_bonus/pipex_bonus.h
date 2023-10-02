#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_tools
{
	int		input_file;
	int		output_file;
	int		flag_hd;
	int		flag_check_file;
	int		cmd_start_index;
	char	**envp_path;
	char	*limiter;
	char	*output_file_name;
}				t_tools;

# define FTERROR -1
# define FTFALSE 0
# define FTTRUE 1

int		ft_free(int error_flag, char **strs, char *str);
void	ft_preset(int argc, char **argv, char **envp, t_tools *tools);
void	ft_making(int argc, char **argv, char **envp, t_tools *tools);
void	ft_check_file(t_tools *tools);
void	ft_reading_empty(t_tools *tools);
void	ft_reading_hd(t_tools *tools);
void	ft_printf_error(const char *s, ...);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	**ft_makepathname_opt(char *s);
char	**ft_split(char const *s, char c);
#endif
