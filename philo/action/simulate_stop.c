#include "../includes/philo.h"

bool	simulate_stop(t_data *data)
{
	pthread_mutex_lock(&data->lock);
	if (data->dead == true)
	{
		pthread_mutex_unlock(&data->lock);
		return (true);
	}
	pthread_mutex_unlock(&data->lock);
	return (false);
}
