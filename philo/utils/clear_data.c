#include "../includes/philo.h"
#include <stddef.h>

void  clear_data(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->nums_philo)
    {
        pthread_mutex_destroy(&data->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->stop_lock);
    ft_free(data);
}
