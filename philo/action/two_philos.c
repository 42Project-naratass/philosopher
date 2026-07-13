#include "../includes/philo.h"

static void	even_philo(t_philo *philo)
{
	while (simulate_stop(philo->data) == false)
	{
		routine(philo);
		usleep((philo->data->time_sleep + philo->data->time_eat) * 1000); // wait for other philo to do their routine + extra time for operation
	}
}

static void	odd_philo(t_philo *philo)
{
	usleep((philo->data->time_sleep + philo->data->time_eat) * 1000); // wait for other philo to do their routine + extra time for operation
	while (simulate_stop(philo->data) == false)
	{
		routine(philo);
		usleep((philo->data->time_sleep + philo->data->time_eat) * 1000); // wait for other philo to do their routine + extra time for operation
	}
}

void	*two_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2 == 0)
		even_philo(philo);
	else
		odd_philo(philo);
	pthread_exit(0);
}
