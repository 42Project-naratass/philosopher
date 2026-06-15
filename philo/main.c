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

static int	config_init(t_config *config, char *argv[], int argc)
{	
	config->nums_philo = ft_atoi(argv[1]);
	config->time_die = ft_atoi(argv[2]);
	config->time_eat = ft_atoi(argv[3]);
	config->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (!check_nums(argv[5]) && ft_atoi(argv[5]) < 1)
			return (1);
		config->min_eat = ft_atoi(argv[5]);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_config	config;

    if (argc != 5 && argc != 6)
		return (1);
	if (input_checker(argv))
		return (1);
	if (config_init(&config, argv, argc))
		return (1);
	philo_simulate(&config);
    return (0);
}
