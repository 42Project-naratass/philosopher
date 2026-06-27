#include "../philo.h"

void	ft_free(t_data *data)
{
    if (data->tid)
        free(data->tid);
    if (data->philos)
        free(data->philos);
    if (data->forks)
        free(data->forks);
}
