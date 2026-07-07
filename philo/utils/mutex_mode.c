#include "../includes/philo.h"

void	mutex_mode(pthread_mutex_t *mutex, t_mode mode, t_data *data)
{
	if (mode == INIT_MUTEX)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			error_exit(EXIT_FAILURE, MUTEX_INIT_FAIL, data);
	}
}
