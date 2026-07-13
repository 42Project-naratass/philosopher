#include "../includes/philo.h"

void	*one_philo(void *arg)
{	
    t_philo	*philo;

    philo = arg;
    pthread_mutex_lock(philo->left_fork);
    print_status(philo, GET_LEFT_FORK, elapsed_time(philo->data->start_time));
    usleep(philo->data->time_die * 1000);
    print_status(philo, DIED, elapsed_time(philo->data->start_time));
    pthread_mutex_unlock(philo->left_fork);
    pthread_exit(0);
}
