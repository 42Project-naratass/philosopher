#include "../philo.h"
#include <stddef.h>
#include <stdio.h>

void  monitor(t_data *data)
{
    size_t  i;
    size_t  timestamp;

    while (1)
    {
        i = 0;
        while (i < data->nums_philo)
        {
			pthread_mutex_lock(&data->lock);
            if (!data->philos[i].eating && elapsed_time(data->philos[i].last_eat) >= data->time_die)
            {
				pthread_mutex_lock(&data->stop_lock);
                data->dead = true;
				pthread_mutex_unlock(&data->stop_lock);
                timestamp = elapsed_time(data->start_time);
                pthread_mutex_lock(&data->print);
                log_display(timestamp, data->philos[i].id, DIED);
                pthread_mutex_unlock(&data->print);
				pthread_mutex_unlock(&data->lock);
                return ;
            }
			pthread_mutex_unlock(&data->lock);
            i++;
        }
    }
}
