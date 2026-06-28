#include "../philo.h"

static void philo_init(t_data *data, t_philo *philo, size_t id)
{
    if (!philo)
        ft_exit(1);
    memset(philo, 0, sizeof(t_philo));
    philo->data = data;
    philo->id = id;
    philo->last_eat = get_time();
    philo->left_fork = philo->data->forks[]
}

int	philo_simulate(t_data *data)
{
    size_t		i;

    i = 0;
    data->start_time = get_time();
    while (i < data->nums_philo)
    {
        philo_init(data, &data->philos[i], i + 1);
        pthread_create(&data->tid[i], NULL, philo, &data->philos[i]);
        i++;
    }
    monitor(data);
    i = 0;
    while(i < data->nums_philo)
    {
        pthread_join(data->tid[i], NULL);
        ++i;
    }
    clear_data(data);
    return (0);
}
