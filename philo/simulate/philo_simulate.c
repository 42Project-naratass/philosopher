#include "../philo.h"

static void	*philo_config(t_config *config, size_t id)
{
	t_config	*thread_config;

	thread_config = (t_config *) malloc(sizeof(t_config));
	ft_memcpy(thread_config, config, sizeof(t_config));
	thread_config->philo_id = id;
	return (thread_config);
}

void	philo_simulate(t_config *config)
{
	pthread_t	philo_thread[config->nums_philo];
	size_t		i;

	i = 0;
	gettimeofday(&config->start_time, NULL);
	while (i < config->nums_philo)
	{
		pthread_create(&philo_thread[i], NULL, philo, philo_config(config, i + 1));
		i++;
	}
	i = 0;
	while (i < config->nums_philo)
	{
		pthread_join(philo_thread[i], NULL);
		i++;
	}
}
