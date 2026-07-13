#include "../includes/philo.h"

void	routine(t_philo *philo)
{
	mutex_mode(philo->left_fork, LOCK_MUTEX, philo->data);	
	print_status(philo, GET_LEFT_FORK, elapsed_time(philo->data->start_time));
	mutex_mode(philo->right_fork, LOCK_MUTEX, philo->data);	
	print_status(philo, GET_RIGHT_FORK, elapsed_time(philo->data->start_time));
	print_status(philo, EATING, elapsed_time(philo->data->start_time));
	usleep(philo->data->time_eat * 1000);
	mutex_mode(philo->left_fork, UNLOCK_MUTEX, philo->data);
	mutex_mode(philo->right_fork, UNLOCK_MUTEX, philo->data);
	philo->last_eat = get_time();
	print_status(philo, SLEEPING, elapsed_time(philo->data->start_time));
	usleep(philo->data->time_sleep * 1000);
	print_status(philo, THINKING, elapsed_time(philo->data->start_time));
}
