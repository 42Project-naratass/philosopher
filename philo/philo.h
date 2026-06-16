#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/time.h>
# include "err.h"

typedef struct	s_data
{
	size_t			philo_id;
	size_t			nums_philo;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			min_eat;
	size_t			times_eat;
	size_t			start_time;
}				t_data;

typedef struct	s_phio

void	philo_simulate(t_config *config);
void	*philo(void *arg);

// utils
size_t	ft_strlen(char *s);
void	putstr_fd(char *str, int fd);
double	ft_atof(char *nbtr);
double	ft_strtod(char *str, char **endptr);
int		ft_atoi(char *nptr);
bool	check_nums(char *str);
int		is_digit(int c);
bool	is_space(char c);
void	ft_exit(int error_code);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	get_time(void);

#endif
