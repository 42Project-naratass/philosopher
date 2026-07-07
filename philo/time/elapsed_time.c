#include "../includes/philo.h"

size_t	elapsed_time(size_t t0)
{
    size_t	t1;

    t1 = get_time();
    return (t1 - t0);
}
