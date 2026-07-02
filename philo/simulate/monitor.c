#include "../philo.h"
#include <stddef.h>
#include <stdio.h>

void  monitor(t_data *data)
{
    size_t  i;
    size_t  timestamp;

    while (!data->dead)
    {
        i = 0;
        while (i < data->nums_philo)
        {
            if (!data->philos[i].eating && elapsed_time(data->philos[i].last_eat) >= data->time_die)
            {
                data->dead = true;
                timestamp = elapsed_time(data->start_time);
                pthread_mutex_lock(&data->print);
                log_display(timestamp, data->philos[i].id, DIED);
                pthread_mutex_unlock(&data->print);
                return ;
            }
            i++;
        }
    }
}
