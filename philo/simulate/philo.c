#include "../philo.h"

static size_t	elapsed_time(const struct timeval t0)
{
	size_t			elapsed;
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	elapsed = (t1.tv_sec - t0.tv_sec) * 1000 + ((t1.tv_usec - t0.tv_usec) / 1000);
	return (elapsed);
}

void	*philo(void *arg)
{
	t_config		*config;
	struct timeval	time_since_last_eat;

	config = arg;
	gettimeofday(&time_since_last_eat, NULL);
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
