#include "../philo.h"
#include <stddef.h>
#include <stdio.h>

void  monitor(t_data *data)
{
    size_t  i;

    while (1)
    {
        i = 0;
        while (i < data->nums_philo)
        {
			pthread_mutex_lock(&data->lock);
            if (data->philos[i].eating == false && elapsed_time(data->philos[i].last_eat) >= data->time_die)
            {
                data->dead = true;
				pthread_mutex_unlock(&data->lock);
				print_status(&data->philos[i], DIED, elapsed_time(data->start_time));
                return ;
            }
			pthread_mutex_unlock(&data->lock);
            i++;
        }
    }
}
