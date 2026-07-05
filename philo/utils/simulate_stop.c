#include "../philo.h"

bool	simulate_stop(t_data *data)
{
	pthread_mutex_lock(&data->stop_lock);
	if (data->dead == true)
	{
		pthread_mutex_unlock(&data->stop_lock);
		return (true);
	}
	pthread_mutex_unlock(&data->stop_lock);
	return (false);
}
