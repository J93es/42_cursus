#include "../inc/philo.h"

static void	ft_free_sub(t_tools *tools)
{
	int	i;

	if (tools->m_fork != NULL)
	{
		i = -1;
		while (++i < tools->philo_num)
			pthread_mutex_destroy(&tools->m_fork[i]);
		free(tools->m_fork);
	}
	if (tools->philo != NULL)
	{
		i = -1;
		while (++i < tools->philo_num)
		{
			pthread_mutex_destroy(&tools->philo[i].m_self);
			pthread_mutex_destroy(&tools->philo[i].m_eat);
		}
		free(tools->philo);
	}
}

static int	ft_free(int return_num, t_tools *tools)
{
	int			i;
	int			j;
	static int	status = 0;

	if (status != 0)
		return (return_num);
	status = 1;
	i = -1;
	while (++i < 3)
	{
		j = tools->philo_num;
		while (--j > -1)
		{
			pthread_mutex_unlock(&tools->philo[j].m_eat);
			pthread_mutex_unlock(&tools->philo[j].m_self);
			pthread_mutex_unlock(&tools->m_fork[j]);
			usleep(1000);
		}
	}
	usleep(300000);
	ft_free_sub(tools);
	pthread_mutex_destroy(&tools->m_print);
	pthread_mutex_destroy(&tools->m_end);
	return (return_num);
}

int	main(int argc, char **argv)
{
	t_tools	tools;

	tools.time_to_start = ft_get_time();
	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	if (ft_preset(&tools, argc, argv) != 0)
		return (EXIT_FAILURE);
	if (ft_threading(&tools) != 0)
		return (ft_free(EXIT_FAILURE, &tools));
	return (ft_free(EXIT_SUCCESS, &tools));
}
