#include "philo.h"

int	main(int argc, char *argv[])
{
	t_config	config;
    if (argc == 5 || argc == 6)
    {
		if (!check_nums(argv[1]) || !check_nums(argv[2])
			|| !check_nums(argv[3]) || !check_nums(argv[4]))
		ft_exit(1);
		config.nums_philo = ft_atoi(argv[1]);
		config.time_die = ft_atoi(argv[2]);
		config.time_eat = ft_atoi(argv[3]);
		config.time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			config.min_eat = ft_atoi(argv[5]);
		philo_simulate(&config);
    }
	else
		ft_exit(1);
    return (0);
}
