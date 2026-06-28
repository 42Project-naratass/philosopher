#include "../philo.h"
#include <stddef.h>
#include <stdio.h>

void  monitor(t_data *data)
{
    size_t i;

    while (!data->dead)
    {
        i = 0;
        while (i < data->nums_philo)
        {
            if (!data->philos[i].eating && elapsed_time(data->philos[i].last_eat) >= data->time_die)
            {
                data->dead = true;
                printf("%zu philospher%zu died\n", elapsed_time(data->start_time), data->philos[i].id);
                return ;
            }
            i++;
        }
    }
}
