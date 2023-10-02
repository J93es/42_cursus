#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				idx;
	long long		die_time;
	long long		last_eat_time;
	int				l_fork;
	int				r_fork;
	struct s_tools	*tools;
	pthread_mutex_t	m_self;
	pthread_mutex_t	m_eat;
}				t_philo;

typedef struct s_tools
{
	int				isend;
	int				philo_num;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				num_to_must_eat;
	long long		time_to_start;
	struct s_philo	*philo;
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_end;
}				t_tools;

int			ft_preset(t_tools *tools, int argc, char **argv);
int			ft_threading(t_tools *tools);
void		ft_philo_cycle(t_philo *philo);
long long	ft_get_time(void);
int			ft_isend(t_tools *tools);
void		ft_philo_printf(t_philo *philo, char *str, int flag);
int			ft_ending(int return_num, t_tools *tools, int flag);
#endif
