#include "../includes/philo.h"

static void	print_log(size_t timestamp, size_t id, char *status)
{
	printf("%zu %zu %s\n", timestamp, id, status);
}

void  print_status(t_philo *philo, t_status mode, size_t timestamp)
{
	pthread_mutex_lock(&philo->data->print);
	if (mode == DIED)
		print_log(timestamp, philo->id, R "died" RST);
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
		print_log(timestamp, philo->id, "has taken a fork");
	else if (mode == GET_RIGHT_FORK)
		print_log(timestamp, philo->id, "has taken a fork");
	pthread_mutex_unlock(&philo->data->print);
}
