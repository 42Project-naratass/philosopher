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

int	main(int argc, char *argv[])
{
	t_data	data;

    if (argc != 5 && argc != 6)
		ft_exit(1);
	if (input_checker(argv))
		ft_exit(1);
	if (data_init(&data, argv, argc))
	{
		printf("Bug here\n");
		ft_exit(1);
	}
	philo_simulate(&data);
  return (0);
}
