#include "../philo.h"

void  log_display(size_t timestamp, size_t id, char *status)
{
    printf("%zu philosopher%zu %s\n", timestamp, id, status);
}
