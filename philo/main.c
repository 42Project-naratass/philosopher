#include "philo.h"

int	main(int argc, char *argv[])
{
	int	number_of_times_each_philosopher_must_eat = 0;
    if (argc == 5 || argc == 6)
    {
		if (!check_nums(argv[1]) || !check_nums(argv[2])
			|| !check_nums(argv[3]) || !check_nums(argv[4]))
		ft_exit(1);
		int	number_of_philosophers = atoi(argv[0]);
		int	time_to_die = atoi(argv[1]);
		int	time_to_eat = atoi(argv[2]);
		int	time_to_sleep = atoi(argv[3]);
		if (argc == 6)
			number_of_times_each_philosopher_must_eat = atoi(argv[5]);
    }
	else
		ft_exit(1);
    return (0);
}
