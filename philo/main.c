#include "includes/philo.h"

static void	input_checker(char *argv[])
{
    if (!check_nums(argv[1]) || !check_nums(argv[2])
        || !check_nums(argv[3]) || !check_nums(argv[4]))
        error_exit(EXIT_FAILURE, INVALID_INPUT, NULL);
    if (ft_atoi(argv[1]) < 1)
	error_exit(EXIT_FAILURE, INVALID_PHILO, NULL);
}

int	main(int argc, char *argv[])
{
    t_data	data;

    if (argc != 5 && argc != 6)
        error_exit(EXIT_FAILURE, INVALID_INPUT, NULL); 
    input_checker(argv);
    data_init(&data, argv, argc);
    philo_simulate(&data);
    return (0);
}
