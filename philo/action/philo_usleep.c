#include "../includes/philo.h"

void	philo_usleep(t_data *data, size_t time)
{	
	size_t	wake_time;

	wake_time = get_time() + time;
	while (get_time() < wake_time)
	{
		if (simulate_stop(data) == true)
			break ;
		usleep(100);
	}
}

