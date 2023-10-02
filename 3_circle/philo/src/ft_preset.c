#include "../inc/philo.h"

static int	ft_atoi(const char *str)
{
	int				n;
	long			p;
	unsigned long	num;

	n = 0;
	p = 1;
	num = 0;
	while (*str != 0 && (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			p = -1;
	while ('0' <= *(str + n) && *(str + n) <= '9')
		num = 10 * num + *(str + n++) - '0';
	return ((int)p * (int)num);
}

static void	ft_set_mutex(t_tools *tools)
{
	int	i;

	pthread_mutex_init(&tools->m_print, NULL);
	pthread_mutex_init(&tools->m_end, NULL);
	i = -1;
	while (++i < tools->philo_num)
	{
		pthread_mutex_init(&tools->m_fork[i], NULL);
		pthread_mutex_init(&tools->philo[i].m_self, NULL);
		pthread_mutex_init(&tools->philo[i].m_eat, NULL);
		pthread_mutex_lock(&tools->philo[i].m_eat);
	}
}

static void	ft_set_philo(t_tools *tools)
{
	int	i;

	i = -1;
	while (++i < tools->philo_num)
	{
		tools->philo[i].idx = i;
		tools->philo[i].l_fork = i;
		if (i == tools->philo_num - 1)
			tools->philo[i].r_fork = 0;
		else
			tools->philo[i].r_fork = i + 1;
		tools->philo[i].tools = tools;
	}
}

static int	ft_set_tools(int argc, char **argv, t_tools *tools)
{
	tools->philo_num = ft_atoi(argv[1]);
	tools->time_to_die = ft_atoi(argv[2]);
	tools->time_to_eat = ft_atoi(argv[3]);
	tools->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		tools->num_to_must_eat = ft_atoi(argv[5]);
	else
		tools->num_to_must_eat = -1;
	if (tools->philo_num < 1 || tools->time_to_die < 0 \
		|| tools->time_to_eat < 0 || tools->time_to_sleep < 0 \
		|| (tools->num_to_must_eat < 0 && argc == 6))
		return (1);
	tools->philo = malloc(sizeof(t_philo) * tools->philo_num);
	if (tools->philo == NULL)
		return (1);
	tools->m_fork = malloc(sizeof(pthread_mutex_t) * tools->philo_num);
	if (tools->m_fork == NULL)
	{
		free(tools->philo);
		tools->philo = NULL;
		return (1);
	}
	return (0);
}

int	ft_preset(t_tools *tools, int argc, char **argv)
{
	tools->philo = NULL;
	tools->m_fork = NULL;
	tools->isend = 0;
	if (ft_set_tools(argc, argv, tools) != 0)
		return (EXIT_FAILURE);
	ft_set_philo(tools);
	ft_set_mutex(tools);
	return (EXIT_SUCCESS);
}
