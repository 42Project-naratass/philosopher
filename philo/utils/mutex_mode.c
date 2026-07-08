#include "../includes/philo.h"

void	mutex_mode(pthread_mutex_t *mutex, t_mode mode, t_data *data)
{
	if (mode == INIT_MUTEX)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			error_exit(EXIT_FAILURE, MUTEX_INIT_FAIL, data);
	}
	else if (mode == DESTROY_MUTEX)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			error_exit(EXIT_FAILURE, MUTEX_DESTROY_FAIL, data);
	}
	else if (mode == LOCK_MUTEX)
	{
		if (pthread_mutex_lock(mutex) != 0)
			error_exit(EXIT_FAILURE, LOCK_FAIL, data);
	}
	else if (mode == UNLOCK_MUTEX)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			error_exit(EXIT_FAILURE, UNLOCK_FAIL, data);
	}
}
