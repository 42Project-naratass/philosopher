#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include "err.h"

// utils
size_t	ft_strlen(char *s);
void	putstr_fd(char *str, int fd);
double	ft_atof(char *nbtr);
double	ft_strtod(char *str, char **endptr);
int		ft_atoi(char *nptr);
bool	check_nums(char *str);
int		is_digit(int c);
bool	is_space(char c);

#endif
