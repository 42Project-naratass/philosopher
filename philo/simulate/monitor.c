#include "../philo.h"

void  monitor(t_data *data)
{
    int i;

    while (true)
    {
        i = 0;
        while (i < data->nums_philo)
        {
            if (elapsed_time(data->philos[i].last_eat) >= data->time_die)
            {
                printf("%zu philospher%zu died\n", elapsed_time(data->start_time), data->philos[i].id);
                data->dead = true;
            }
        }
    }
}
