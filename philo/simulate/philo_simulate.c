#include "../philo.h"

static void	*philo_config(t_data *share_data, size_t id)
{
	t_philo	*philo;

	philo = (t_philo *) malloc(sizeof(t_philo));
	if (!philo)
		ft_exit(1);
	memset(philo, 0, sizeof(t_philo));
	philo->data = share_data;
	philo->id = id;
	return (philo);
}

void	philo_simulate(t_data *data)
{
	size_t		i;

	i = 0;
	data->start_time = get_time();
	while (i < data->nums_philo)
	{
		pthread_create(&data->philos[i], NULL, philo, philo_config(data, i + 1));
		i++;
	}
	i = 0;
	while (i < data->nums_philo)
	{
		pthread_join(data->philos[i], NULL);
		i++;
	}
}
