#include "../inc/philo.h"

static void	ft_philo_waiting_fork(t_philo *philo)
{
	if (philo->idx % 2 == 0)
	{
		pthread_mutex_lock(&philo->tools->m_fork[philo->r_fork]);
		ft_philo_printf(philo, "has taken a fork", 0);
		pthread_mutex_lock(&philo->tools->m_fork[philo->l_fork]);
		ft_philo_printf(philo, "has taken a fork", 0);
	}
	else
	{
		pthread_mutex_lock(&philo->tools->m_fork[philo->l_fork]);
		ft_philo_printf(philo, "has taken a fork", 0);
		pthread_mutex_lock(&philo->tools->m_fork[philo->r_fork]);
		ft_philo_printf(philo, "has taken a fork", 0);
	}
}

static void	ft_philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_self);
	philo->last_eat_time = ft_get_time();
	philo->die_time = philo->last_eat_time + philo->tools->time_to_die;
	ft_philo_printf(philo, "is eating", 0);
	if (ft_isend(philo->tools) == 0)
		usleep(philo->tools->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->m_self);
	pthread_mutex_unlock(&philo->m_eat);
}

static void	ft_philo_sleeping(t_philo *philo)
{
	pthread_mutex_unlock(&philo->tools->m_fork[philo->l_fork]);
	pthread_mutex_unlock(&philo->tools->m_fork[philo->r_fork]);
	ft_philo_printf(philo, "is sleeping", 0);
	if (ft_isend(philo->tools) == 0)
		usleep(philo->tools->time_to_sleep * 1000);
	ft_philo_printf(philo, "is thinking", 0);
}

void	ft_philo_cycle(t_philo *philo)
{
	ft_philo_waiting_fork(philo);
	ft_philo_eating(philo);
	ft_philo_sleeping(philo);
	usleep(100);
}
