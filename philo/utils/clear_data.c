#include "../philo.h"
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
    ft_free(data);
}
