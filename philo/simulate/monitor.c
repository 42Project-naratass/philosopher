#include "../philo.h"
#include <stddef.h>

void  monitor(t_data *data)
{
    size_t i;

    printf("Monitor is working..\n");
    if (data->dead == true)
        printf("Is dead\n");
    while (1)
    {
        i = 0;
        while (i < data->nums_philo)
        {
            if (elapsed_time(data->philos[i].last_eat) >= data->time_die)
            {
                data->dead = true;
                printf("%zu philospher%zu died\n", elapsed_time(data->start_time), data->philos[i].id);
                return ;
            }
            i++;
        }
    }
}
