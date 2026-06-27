#include "../philo.h"
#include <stddef.h>

void	*philo(void *arg)
{
    t_philo	*philo;

    philo = arg;
    philo->last_eat = get_time();
    while (!philo->data->dead)
    {
        printf("%zu philospher%zu is thinking\n", elapsed_time(philo->data->start_time), philo->id);
    }
    pthread_exit(0);
}
