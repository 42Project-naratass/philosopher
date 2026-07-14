#include "../includes/philo.h"

void	*philos(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (simulate_stop(philo->data) == false)
		routine(philo);
	pthread_exit(0);
}
