#include "../philo.h"

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (size_t)1000) + (tv.tv_usec / 1000));
}
