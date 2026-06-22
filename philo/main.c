#include "philo.h"

static int input_checker(char *argv[])
{
	if (!check_nums(argv[1]) || !check_nums(argv[2])
		|| !check_nums(argv[3]) || !check_nums(argv[4]))
		return (1);
	if (ft_atoi(argv[1]) < 1)
		return (1);
	else
		return (0);
}

static int	data_init(t_data *data, char *argv[], int argc)
{	
	data->nums_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (!check_nums(argv[5]) && ft_atoi(argv[5]) < 1)
			return (1);
		data->min_eat = ft_atoi(argv[5]);
	}
	data->dead = false;
	data->philos = (pthread_t *) malloc(sizeof(pthread_t) * data->nums_philo);
	if (!data->philos)
		return (1);
	data->forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * data->nums_philo);
	if (!data->forks)
	    return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

    if (argc != 5 && argc != 6)
		return (1);
	if (input_checker(argv))
		return (1);
	if (data_init(&data, argv, argc))
		return (1);
	philo_simulate(&data);
    return (0);
}
