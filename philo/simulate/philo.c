#include "../philo.h"
#include <stddef.h>

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
	while (!philo->data->dead)
	{
        if (elapsed_time(time_since_last_eat) >= philo->data->time_die && !philo->eating)
        {
          pthread_mutex_lock(&philo->data->write);
          if (!philo->data->dead)
          {
            printf("%zu philosophers%zu died\n", elapsed_time(philo->data->start_time), philo->id);
            philo->data->dead = true;
          }
          pthread_mutex_unlock(&philo->data->write);
          free(philo);
          pthread_exit(0);
        }
        pthread_mutex_lock(&philo->data->forks[(philo->id + 1) % philo->data->nums_philo]);
        pthread_mutex_lock(&philo->data->forks[(philo->id - 1 + philo->data->nums_philo) % philo->data->nums_philo]);
        philo->eating = true;
        printf("%zu philosophers%zu eating\n", elapsed_time(philo->data->start_time), philo->id);
        usleep(philo->data->time_eat); 
        time_since_last_eat = get_time();
        philo->eating = false;
        pthread_mutex_unlock(&philo->data->forks[(philo->id - 1 + philo->data->nums_philo) % philo->data->nums_philo]);
        pthread_mutex_unlock(&philo->data->forks[(philo->id + 1) % philo->data->nums_philo]); 
        printf("%zu philosophers%zu sleeping\n", elapsed_time(philo->data->start_time), philo->id);
        usleep(philo->data->time_sleep);
	}
        free(philo);
        pthread_exit(0);
}
