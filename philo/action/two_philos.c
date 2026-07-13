#include "../includes/philo.h"

void	*two_philo(void *arg)
{
    t_philo	*philo;

    philo = arg;
    if (philo->id % 2 == 0)
    {
	routine(philo);
	usleep((philo->data->time_sleep + philo->data->time_eat) * 1000 + OP_TIME); // wait for other philo to do their routine + extra time for operation
    }
    else
    {
	usleep((philo->data->time_sleep + philo->data->time_eat) * 1000 + OP_TIME); // wait for other philo to do their routine + extra time for operation
	routine(philo);
	usleep((philo->data->time_sleep + philo->data->time_eat) * 1000 + OP_TIME); // wait for other philo to do their routine + extra time for operation
    }
    pthread_exit(0);
}
