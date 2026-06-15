#include "../philo.h"

static size_t	elapsed_time(size_t t0)
{
	size_t	t1;

	t1 = get_time();
	return (t1 - t0);
}

void	*philo(void *arg)
{
	t_config	*config;
	size_t		time_since_last_eat;

	config = arg;
	time_since_last_eat = get_time();
	while (true)
	{	
		if (elapsed_time(time_since_last_eat) >= config->time_die)
		{
			printf("%zu philosophers%zu died\n", elapsed_time(config->start_time), config->philo_id);
			free(config);
			pthread_exit(NULL);
			exit(0);
		}
		printf("%zu philosophers%zu thinking\n", elapsed_time(config->start_time), config->philo_id);
	}
	return (NULL);
}
