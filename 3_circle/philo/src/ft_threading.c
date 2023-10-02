#include "../inc/philo.h"

static void	*ft_isend_all_full(void *philo_argv)
{
	int		i;
	int		eat_cnt;
	t_tools	*tools;

	eat_cnt = 0;
	tools = ((t_philo *)philo_argv)->tools;
	while (ft_isend(tools) == 0)
	{
		i = -1;
		while (++i < tools->philo_num && ft_isend(tools) == 0)
			pthread_mutex_lock(&tools->philo[i].m_eat);
		eat_cnt++;
		if (eat_cnt == tools->num_to_must_eat)
		{
			if (ft_isend(tools) == 0)
				ft_ending(0, tools, -1);
			return (0);
		}
	}
	return (0);
}

static void	*ft_isend_one_died(void *philo_argv)
{
	t_philo		*philo;

	philo = (t_philo *)philo_argv;
	while (ft_isend(philo->tools) == 0)
	{
		pthread_mutex_lock(&philo->m_self);
		if (ft_get_time() > philo->die_time)
		{
			pthread_mutex_unlock(&philo->m_self);
			if (ft_isend(philo->tools) == 0)
				ft_ending(0, philo->tools, philo->idx);
			return (0);
		}
		pthread_mutex_unlock(&philo->m_self);
		usleep(1000);
	}
	return (0);
}

static void	*ft_philo_acting(void *philo_argv)
{
	pthread_t	tid;
	t_philo		*philo;

	philo = (t_philo *)philo_argv;
	philo->last_eat_time = philo->tools->time_to_start;
	philo->die_time = philo->last_eat_time + philo->tools->time_to_die;
	if (philo->idx % 2 == 1)
		usleep(100);
	if (pthread_create(&tid, NULL, &ft_isend_one_died, philo_argv) != 0)
	{
		if (ft_isend(philo->tools) == 0)
			ft_ending(0, philo->tools, -1);
		return ("1");
	}
	pthread_detach(tid);
	while (ft_isend(philo->tools) == 0)
		ft_philo_cycle(philo);
	return (0);
}

int	ft_threading(t_tools *tools)
{
	int			i;
	pthread_t	tid;

	if (tools->num_to_must_eat != -1)
	{
		if (pthread_create
			(&tid, NULL, &ft_isend_all_full, (void *)tools->philo) != 0)
			return (ft_ending(EXIT_FAILURE, tools, -1));
		pthread_detach(tid);
	}
	i = -1;
	while (++i < tools->philo_num)
	{
		if (pthread_create
			(&tid, NULL, &ft_philo_acting, (void *)(&tools->philo[i])) != 0)
			return (ft_ending(EXIT_FAILURE, tools, -1));
		pthread_detach(tid);
	}
	while (ft_isend(tools) != -1)
		usleep(10000);
	return (EXIT_SUCCESS);
}
