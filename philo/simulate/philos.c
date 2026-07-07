#include "../philo.h"
#include <stddef.h>

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, GET_LEFT_FORK, elapsed_time(philo->data->start_time));
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, GET_RIGHT_FORK, elapsed_time(philo->data->start_time));
	pthread_mutex_lock(&philo->data->lock);
	philo->eating = true;
	philo->last_eat = get_time();
	if (philo->data->min_eat > 0)
		philo->meals_eat++;
	pthread_mutex_unlock(&philo->data->lock);
	print_status(philo, EATING, elapsed_time(philo->data->start_time));
	usleep(philo->data->time_sleep * 1000);
	//philo_usleep(philo->data, philo->data->time_eat);
	pthread_mutex_lock(&philo->data->lock);
	philo->eating = false;
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*philos(void *arg)
{
    t_philo	*philo;

    philo = arg;
    while (simulate_stop(philo->data) == false)
    {
		print_status(philo, THINKING, elapsed_time(philo->data->start_time));
        eating(philo);
		print_status(philo, SLEEPING, elapsed_time(philo->data->start_time));
		usleep(philo->data->time_sleep * 1000);
		//philo_usleep(philo->data, philo->data->time_sleep);
    }
    pthread_exit(0);
}
