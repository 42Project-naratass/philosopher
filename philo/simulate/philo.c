#include "../philo.h"
#include <stddef.h>

static void	eating(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    pthread_mutex_lock(philo->right_fork);
    philo->eating = true;
    printf("%zu philospher%zu is eating\n", elapsed_time(philo->data->start_time), philo->id);
    usleep(philo->data->time_eat);
    philo->eating = false;
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void	*philo(void *arg)
{
    t_philo	*philo;

    philo = arg;
    while (!philo->data->dead)
    {
        printf("%zu philospher%zu is thinking\n", elapsed_time(philo->data->start_time), philo->id);
        eating(philo);
	philo->last_eat = get_time();
        printf("%zu philospher%zu is sleeping\n", elapsed_time(philo->data->start_time), philo->id);
	usleep(philo->data->time_sleep);

    }
    pthread_exit(0);
}
