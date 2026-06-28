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
# include "err.h"

struct s_data;

typedef struct	s_philo
{
    struct s_data	  *data;
    size_t          id;
    bool	          eating;
    size_t					last_eat;
    pthread_mutex_t	*left_fork;
    pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct	s_data
{
    t_philo           *philos;
    pthread_t					*tid;
    size_t			      nums_philo;
    size_t			      time_die;
    size_t			      time_eat;
    size_t			      time_sleep;
    size_t			      min_eat;
    size_t			      times_eat;
    size_t			      start_time;
    bool			        dead;
    pthread_mutex_t		*forks;
    pthread_mutex_t   print;
}	t_data;

// simulate
int	    philo_simulate(t_data *data);
void	  *philo(void *arg);
void    monitor(t_data *data);

int     data_init(t_data *data, char *argv[], int argc);

// utils
size_t	ft_strlen(char *s);
void	  putstr_fd(char *str, int fd);
double	ft_atof(char *nbtr);
double	ft_strtod(char *str, char **endptr);
int		  ft_atoi(char *nptr);
bool	  check_nums(char *str);
int	  	is_digit(int c);
bool	  is_space(char c);
void	  ft_exit(int error_code);
void	  *ft_memcpy(void *dst, const void *src, size_t n);
size_t	get_time(void);
void		ft_free(t_data *data);
void    clear_data(t_data *data);
size_t  elapsed_time(size_t t0);

#endif
