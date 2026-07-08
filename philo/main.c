#include "includes/philo.h"

static bool input_checker(char *argv[])
{
    if (!check_nums(argv[1]) || !check_nums(argv[2])
        || !check_nums(argv[3]) || !check_nums(argv[4]))
        error_exit(EXIT_FAILURE, INVALID_INPUT, NULL);
    if (ft_atoi(argv[1]) < 1)
		error_exit(EXIT_FAILURE, INVALID_PHILO, NULL);
    else
        return (0);
}

int	main(int argc, char *argv[])
{
    t_data	data;

    if (argc != 5 && argc != 6)
        
    if (input_checker(argv) == false)
        ft_exit(1);
    if (data_init(&data, argv, argc))
        ft_exit(1);
    philo_simulate(&data);
    return (0);
}
