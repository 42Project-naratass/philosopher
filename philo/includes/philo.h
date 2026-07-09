#ifndef PHILO_H
# define PHILO_H
#include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/time.h>
# include <string.h>
# include "../includes/message.h"

struct s_data;

typedef struct	s_philo
{
	pthread_t		tid;
    struct s_data	*data;
    size_t          id;
    bool			eating;
    size_t			last_eat;
	size_t			meals_eat;
    pthread_mutex_t	*left_fork;
    pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct	s_data
{
    t_philo			*philos;
    pthread_t		*tid;
    size_t			nums_philo;
    size_t			time_die;
    size_t			time_eat;
    size_t			time_sleep;
    size_t			min_eat;
    size_t			times_eat;
    size_t			start_time;
    bool			dead;
    pthread_mutex_t	*forks;
    pthread_mutex_t print;
	pthread_mutex_t	lock;
	pthread_mutex_t	stop_lock;
}	t_data;

typedef enum	e_status
{
	DIED,
	EATING,
	SLEEPING,
	THINKING,
	GET_LEFT_FORK,
	GET_RIGHT_FORK,
}	t_status;

typedef enum e_mode
{
	CREATE_THREAD,
	JOIN_THREAD,
	INIT_MUTEX,
	DESTROY_MUTEX,
	LOCK_MUTEX,
	UNLOCK_MUTEX,
}	t_mode;

// simulate
void	philo_simulate(t_data *data);
void    monitor(t_data *data);

// parser
int     data_init(t_data *data, char *argv[], int argc);
bool	check_nums(char *str);

// action
bool	simulate_stop(t_data *data);
void	*one_philo(void *arg);
void	*two_philo(void *arg);
void	*three_philo(void *arg);

// message
void	print_status(t_philo *philo, t_status mode, size_t timestamp);
void	error_exit(int exit_code, char *msg, t_data *data);

// time
size_t  elapsed_time(size_t t0);
size_t	get_time(void);

// utils
size_t	ft_strlen(char *s);
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(char *nptr);
int	  	is_digit(int c);
bool	is_space(char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_free(t_data *data);
void    clear_data(t_data *data);
void	philo_usleep(t_data *data, size_t time);
void	thread_mode(t_philo *philo, void *(*f)(void *), t_mode mode, t_data *data);
void	mutex_mode(pthread_mutex_t *mutex, t_mode mode, t_data *data)

#endif
