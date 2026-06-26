#include "../philo.h"

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	free(data->philos);
  while (i < data->nums_philo)
    pthread_mutex_destroy(&data->forks[i]);
}