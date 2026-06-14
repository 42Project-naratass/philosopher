#include "../philo.h"

void	*philo(void *arg)
{
	t_config	*config;

	config = arg;
	(void)config;
	printf("Thread create\n");
	sleep(2);
	printf("Thread finish\n");
	return (NULL);
}
