#include "../includes/philo.h"

void	*three_philo(void *arg)
{
   t_philo	*philo;

   philo = arg;
   (void)philo;
   pthread_exit(0);
}
