#include "../philo.h"

void	ft_exit(int error_code)
{
	if (error_code == 1)
	{
		putstr_fd(INVALID_ARG, 2);
		exit(1);
	}
	if (error_code == 2)
	{
		putstr_fd(UNALLOCATED, 2);
		exit(2);
	}
}
