#include "../philo.h"

void	philo_simulate(t_config *config)
{
	pthread_t	philo_thread[config->nums_philo];
	size_t		i;

	i = 0;
	gettimeofday(&config->start_time, NULL);
	while (i < config->nums_philo)
	{
		pthread_create(&philo_thread[i], NULL, philo, config);
		i++;
	}
	i = 0;
	while (i < config->nums_philo)
	{
		pthread_join(philo_thread[i], NULL);
		i++;
	}
}
