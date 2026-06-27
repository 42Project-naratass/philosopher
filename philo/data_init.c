#include "philo.h"
#include <stddef.h>

static int allocate(t_data *data)
{
    data->tid = (pthread_t *) malloc(sizeof(pthread_t) * data->nums_philo);
    if (!data->tid)
        return (1);
    data->forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * data->nums_philo);
    if (!data->forks)
        return (1);
    data->philos = (t_philo *) malloc(sizeof(t_philo) * data->nums_philo);
        return (1);
    return (0);
}

static int mutex(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->nums_philo)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&data->print, NULL);
    return (1);
}

int	data_init(t_data *data, char *argv[], int argc)
{	
    data->nums_philo = ft_atoi(argv[1]);
    data->time_die = ft_atoi(argv[2]);
    data->time_eat = ft_atoi(argv[3]);
    data->time_sleep = ft_atoi(argv[4]);
    data->dead = false;
    if (argc == 6)
    {
        if (!check_nums(argv[5]) && ft_atoi(argv[5]) < 1)
            return (1);
        data->min_eat = ft_atoi(argv[5]);
    }
    if (!allocate(data))
        return (1);
    if (!mutex(data))
        return (1);
    return (0);
}
