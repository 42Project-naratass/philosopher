#include "../includes/philo.h"
#include <stddef.h>
#include <stdio.h>

bool	is_dead(t_philo *philo)
{
	if (philo->eating == false && elapsed_time(philo->last_eat) >= philo->data->time_die)
	{
		philo->data->dead = true;
		pthread_mutex_unlock(&philo->data->lock);
		print_status(philo, DIED, elapsed_time(philo->data->start_time));
		return (true);
	}
	return (false);
}

void  monitor(t_data *data)
{
    size_t  i;
	bool	all_full;

    while (true)
    {
		all_full = true;
        i = 0;
        while (i < data->nums_philo)
        {
			pthread_mutex_lock(&data->lock);
			if (is_dead(&data->philos[i]) == true)
				return ;
			if (data->philos[i].meals_eat < data->min_eat)
				all_full = false;
			if (data->min_eat > 0 && all_full == true)
			{
				data->dead = true;
				pthread_mutex_unlock(&data->lock);
				return ;
			}
			pthread_mutex_unlock(&data->lock);
            i++;
		}
    }
}
