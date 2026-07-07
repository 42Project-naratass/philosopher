#include "../includes/philo.h"

static void	print_log(size_t timestamp, size_t id, char *status)
{
	printf("%zu philosopher %zu %s\n", timestamp, id, status);
}

void  print_status(t_philo *philo, t_status mode, size_t timestamp)
{
	if (mode == DIED)
		print_log(timestamp, philo->id, "died");
	pthread_mutex_lock(&philo->data->print);
	if (simulate_stop(philo->data) == true)
	{
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	if (mode == SLEEPING)
		print_log(timestamp, philo->id, "is sleeping");
	else if (mode == EATING)
		print_log(timestamp, philo->id, "is eating");
	else if (mode == THINKING)
		print_log(timestamp, philo->id, "is thinking");
	else if (mode == GET_LEFT_FORK)
		print_log(timestamp, philo->id, "get taken a fork");
	else if (mode == GET_RIGHT_FORK)
		print_log(timestamp, philo->id, "get taken a fork");
	pthread_mutex_unlock(&philo->data->print);
}
