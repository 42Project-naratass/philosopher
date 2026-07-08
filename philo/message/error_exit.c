#include "../includes/philo.h"

void	error_exit(int exit_code, char *msg, t_data *data)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	if (data)
		clear_data(data);
	exit(exit_code);
}
