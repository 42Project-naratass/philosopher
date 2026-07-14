#include "../includes/philo.h"

void	routine(t_philo *philo)
{
	mutex_mode(philo->left_fork, LOCK_MUTEX, philo->data);
	print_status(philo, GET_LEFT_FORK);
	mutex_mode(philo->right_fork, LOCK_MUTEX, philo->data);
	print_status(philo, GET_RIGHT_FORK);
	print_status(philo, EATING);
	mutex_mode(&philo->data->lock, LOCK_MUTEX, philo->data);
	philo->eating = true;
	mutex_mode(&philo->data->lock, UNLOCK_MUTEX, philo->data);
	usleep(philo->data->time_eat * 1000);
	mutex_mode(philo->left_fork, UNLOCK_MUTEX, philo->data);
	mutex_mode(philo->right_fork, UNLOCK_MUTEX, philo->data);
	if (philo->data->min_eat > 0)
		philo->meals_eat++;
	mutex_mode(&philo->data->lock, LOCK_MUTEX, philo->data);
	philo->eating = false;
	philo->last_eat = get_time();
	mutex_mode(&philo->data->lock, UNLOCK_MUTEX, philo->data);
	print_status(philo, SLEEPING);
	usleep(philo->data->time_sleep * 1000);
	print_status(philo, THINKING);
}
