#include "../philo.h"

void	thread_err(int err_code)
{
	if (err_code == EINVAL)	
		putstr_fd("Invalid thread\n", 2);
	if (err_code == EAGAIN)
		putstr_fd("Can't create thread\n", 2);
	if (err_code == ESRCH)
		putstr_fd("Thread not found\n", 2);
	if (err_code == EDEADLK)
		putstr_fd("Deadlock\n", 2);
	else
		putstr_fd("Thread error\n", 2);
}
