#include "../philo.h"
#include <stddef.h>

static void	eating(t_philo *philo)
{
    size_t  timestamp;

    pthread_mutex_lock(philo->left_fork);
	printf("philo%zu take left fork\n", philo->id);
    pthread_mutex_lock(philo->right_fork);
	printf("philo%zu take right fork\n", philo->id);
	pthread_mutex_lock(philo->lock);
    philo->eating = true;
	pthread_mutex_unlock(philo->lock);
    timestamp = elapsed_time(philo->data->start_time);
    pthread_mutex_lock(&philo->data->print);
    log_display(timestamp, philo->id, EATING);
    pthread_mutex_unlock(&philo->data->print);
    usleep(philo->data->time_eat * 1000);
	pthread_mutex_lock(philo->lock);
    philo->eating = false;
    philo->last_eat = get_time();
	pthread_mutex_unlock(philo->lock);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    timestamp = elapsed_time(philo->data->start_time);
    pthread_mutex_lock(&philo->data->print);
    log_display(timestamp, philo->id, SLEEPING);
    pthread_mutex_unlock(&philo->data->print);
    usleep(philo->data->time_sleep * 1000);
}

void	*philo(void *arg)
{
    t_philo	*philo;
    size_t  timestamp;

    philo = arg;
    while (simulate_stop(philo->data) == false)
    {
        timestamp = elapsed_time(philo->data->start_time);
        pthread_mutex_lock(&philo->data->print);
        log_display(timestamp, philo->id, THINKING);
        pthread_mutex_unlock(&philo->data->print);
        eating(philo); 
    }
    pthread_exit(0);
}
