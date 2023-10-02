#include "../inc/philo.h"

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_isend(t_tools *tools)
{
	int	i;

	pthread_mutex_lock(&tools->m_end);
	i = tools->isend;
	pthread_mutex_unlock(&tools->m_end);
	return (i);
}

void	ft_philo_printf(t_philo *philo, char *str, int flag)
{
	static int			status = 0;
	static long long	time_to_start = -1;

	pthread_mutex_lock(&philo->tools->m_print);
	if (status != 0)
		return ;
	if (time_to_start == -1)
		time_to_start = philo->tools->time_to_start;
	if (flag >= 0 && status == 0)
	{
		if (status == 0 && flag >= 0)
			printf("%lld %d %s\n", \
				ft_get_time() - time_to_start, philo->idx + 1, str);
		if (flag != 0)
			status = 1;
	}
	pthread_mutex_unlock(&philo->tools->m_print);
}

int	ft_ending(int return_num, t_tools *tools, int idx)
{
	static int	status = 0;

	pthread_mutex_lock(&tools->m_end);
	if (status == 0)
	{
		status = 1;
		tools->isend = 1;
		if (idx >= 0)
			ft_philo_printf(&tools->philo[idx], "died", 1);
		else
			ft_philo_printf(&tools->philo[0], "", -1);
		tools->isend = -1;
	}
	pthread_mutex_unlock(&tools->m_end);
	return (return_num);
}
