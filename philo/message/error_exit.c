#include "../includes/philo.h"

void	error_exit(int exit_code, char *msg, int fd, t_data *data)
{
	if (msg)
		ft_putstr_fd(msg, fd);
	if (data)
		clear_data(data);
	exit(exit_code);
}
