#include "../includes/philo.h"

void	thread_mode(t_philo *philo, void *(*f)(void *), t_mode mode, t_data *data)
{
	if (mode == CREATE_THREAD)
	{
		if (pthread_create(&philo->tid, NULL, f, data) != 0)
			error_exit(EXIT_FAILURE, THREAD_CREATE_FAIL, data);
	}
	else if (mode == JOIN_THREAD)
	{
		if (pthread_join(philo->tid, NULL) != 0)
			error_exit(EXIT_FAILURE, THREAD_JOIN_FAIL, data);
	}
}
