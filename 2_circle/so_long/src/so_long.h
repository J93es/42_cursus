#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./mlx/mlx.h"

typedef struct s_imgs
{
	void	*p1;
	void	*p2;
	void	*e1;
	void	*e2;
	void	*c;
	void	*empty;
	void	*wall1;
	void	*wall2;
	void	*ob;
	void	*flag_empty;
	void	*flag_find;
	void	*flag_wall;
	void	*flag_usage;
	void	*win;
	void	*lose;
	void	*press_any_key;
}				t_imgs;

typedef struct s_tools
{
	int		flag;
	int		width;
	int		height;
	int		all_item;
	int		item_cnt;
	int		move_cnt;
	int		p_index[2];
	void	*win;
	void	*mlx;
	char	**map;
	t_imgs	imgs;
}				t_tools;

# define FTEXIT_LOSE -3
# define FTEXIT_WIN -2
# define FTERROR -1
# define FTNORMAL 0
# define FTFLAG_FIND 1
# define FTFLAG_WALL 2
# define FTFLAG_USAGE 3

# define FTKEY_W 13
# define FTKEY_A 0
# define FTKEY_S 1
# define FTKEY_D 2
# define FTKEY_ESC 53

int		ft_free(int return_num, t_tools *tools);
void	ft_map_set(int argc, char **argv, t_tools *tools);
void	ft_img_set(t_tools *tools);
void	ft_put_flag(t_tools *tools);
void	ft_put_img(t_tools *tools);
char	*ft_strrchr(const char *s, int c);
int		ft_printfd(int fd, const char *s, ...);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_finddigit(int n);
char	*ft_itoa(int n);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
#endif
