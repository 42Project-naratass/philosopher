#include "../philo.h"
#include <stddef.h>

void	*philo(void *arg)
{
    t_philo	*philo;

    philo = arg;
    pthread_mutex_init(&philo->data->print, NULL);
    philo = arg;
    philo->last_eat = get_time();
    while (!philo->data->dead)
    {
        printf("%zu philospher%zu is thinking\n", elapsed_time(get_time()), philo->id);
    }
    free(philo);
    pthread_exit(0);
}
