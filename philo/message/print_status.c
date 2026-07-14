#include "../includes/philo.h"

static void	print_log(size_t timestamp, size_t id, char *status)
{
	printf(Y"%zu\t" RST "%zu\t%s\n", timestamp, id, status);
}

void	print_status(t_philo *philo, t_status mode)
{
	size_t	timestamp;

	pthread_mutex_lock(&philo->data->print);
	timestamp = elapsed_time(philo->data->start_time);
	if (mode == DIED)
		print_log(timestamp, philo->id, R "died" RST);
	if (simulate_stop(philo->data) == true)
	{
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	if (mode == SLEEPING)
		print_log(timestamp, philo->id, C "is sleeping" RST);
	else if (mode == EATING)
		print_log(timestamp, philo->id, M "is eating" RST);
	else if (mode == THINKING)
		print_log(timestamp, philo->id, G "is thinking" RST);
	else if (mode == GET_FORK_1)
		print_log(timestamp, philo->id, BK "has taken a fork" RST);
	else if (mode == GET_FORK_2)
		print_log(timestamp, philo->id, BK "has taken a fork" RST);
	pthread_mutex_unlock(&philo->data->print);
}
