#include "../philo.h"

size_t	get_time(void)
{
	struct timeval	tv;
	size_t			usec;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (size_t)1000) + (tv.tv_sec / 1000));
}
