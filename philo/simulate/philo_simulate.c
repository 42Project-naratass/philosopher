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
	philo->lock = &data->lock;
    return (1);
}

int	philo_simulate(t_data *data)
{
    size_t		i;

    i = 0;
    data->start_time = get_time();
    while (i < data->nums_philo)
    {
        if (!philo_init(data, &data->philos[i], i + 1))
            return (1);
        if (pthread_create(&data->tid[i], NULL, philo, &data->philos[i]) != 0)
            return (1);
        i++;
    }
    monitor(data);
	i = 0;
	while (i < data->nums_philo)
		pthread_join(data->tid[i++], NULL);
    clear_data(data);
    return (0);
}
