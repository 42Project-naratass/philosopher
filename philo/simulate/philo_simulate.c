#include "../philo.h"

static int  philo_init(t_data *data, t_philo *philo, size_t id)
{
    if (!philo)
        ft_exit(1);
    memset(philo, 0, sizeof(t_philo));
    philo->data = data;
    philo->id = id;
    philo->left_fork = &philo->data->forks[id - 1];
    philo->right_fork = &philo->data->forks[id % philo->data->nums_philo];
    if (!philo->left_fork || !philo->right_fork)
		return (0);
    philo->last_eat = get_time();
    return (1);
}

static int	sole_philo(t_data *data)
{
	data->start_time = get_time();
	if (!philo_init(data, &data->philos[0], 1))
		return (0);
	if (pthread_create(&data->tid[0], NULL, one_philo, &data->philos[0]) != 0)
		return (0);
	pthread_join(data->tid[0], NULL);
	clear_data(data);
	return (1);
}

static int	multiple_philos(t_data *data)
{
    size_t		i;

    i = 0;
    data->start_time = get_time();
    while (i < data->nums_philo)
    {
        if (!philo_init(data, &data->philos[i], i + 1))
            return (0);
        if (pthread_create(&data->tid[i], NULL, philos, &data->philos[i]) != 0)
            return (0);
        i++;
    }
    monitor(data);
	i = 0;
	while (i < data->nums_philo)
		pthread_join(data->tid[i++], NULL);
    clear_data(data);
    return (1);
}

int	philo_simulate(t_data *data)
{
	if (data->nums_philo == 1)
	{
		if (!sole_philo(data))
			return (0);
	}
	else
	{
		if (!multiple_philos(data))
			return (0);
	}
	return (1);
}
