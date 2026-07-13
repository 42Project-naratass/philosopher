#include "../includes/philo.h"

static void	philo_init(t_data *data, t_philo *philo, size_t id)
{
	if (!philo)
		error_exit(EXIT_FAILURE, INIT_PHILO_FAIL, data);
	memset(philo, 0, sizeof(t_philo));
	philo->tid = data->tid[id - 1];
	philo->data = data;
	philo->id = id;
	philo->left_fork = &philo->data->forks[id - 1];
	philo->right_fork = &philo->data->forks[id % philo->data->nums_philo];
	if (philo->id % 2 == 0)
	{
		philo->right_fork = &philo->data->forks[id - 1];
		philo->left_fork = &philo->data->forks[id % philo->data->nums_philo];
	}
	if (!philo->left_fork || !philo->right_fork)
		error_exit(EXIT_FAILURE, INIT_FORK_PHILO_FAIL, data);
	philo->last_eat = get_time();
}

static void	sole_philo(t_data *data)
{
	data->start_time = get_time();
	philo_init(data, &data->philos[0], 1);
	thread_mode(&data->philos[0], one_philo, CREATE_THREAD, data);
	thread_mode(&data->philos[0], NULL, JOIN_THREAD, NULL);
	clear_data(data);
}

static void	multiple_philos(t_data *data, void *(*f)(void *))
{
	size_t	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->nums_philo)
	{
		philo_init(data, &data->philos[i], i + 1);
		thread_mode(&data->philos[i], f, CREATE_THREAD, data);
		i++;
	}
	monitor(data);
	i = 0;
	while (i < data->nums_philo)
		thread_mode(&data->philos[i++], NULL, JOIN_THREAD, data);
	clear_data(data);
}

void	philo_simulate(t_data *data)
{
	if (data->nums_philo == 1)
		sole_philo(data);
	else
		multiple_philos(data, two_philo);
}
