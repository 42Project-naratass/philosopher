#include "../philo.h"

static size_t	elapsed_time(size_t t0)
{
	size_t	t1;

	t1 = get_time();
	return (t1 - t0);
}

void	*philo(void *arg)
{
	t_philo	*philo;
	size_t	time_since_last_eat;

	philo = arg;
	time_since_last_eat = get_time();
	while (true)
	{
		if (elapsed_time(time_since_last_eat) >= philo->data->time_die)
		{
			printf("%zu philosophers%zu died\n", elapsed_time(philo->data->start_time), philo->id);
			free(philo);
			pthread_exit(NULL);
		}
	}
	return (NULL);
}
