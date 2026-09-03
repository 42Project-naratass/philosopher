/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42Bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 23:10:49 by naratass          #+#    #+#             */
/*   Updated: 2026/09/03 23:12:35 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	allocate(t_data *data)
{
	data->tid = malloc(sizeof(pthread_t) * data->nums_philo);
	if (!data->tid)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nums_philo);
	if (!data->forks)
		return (1);
	data->philos = malloc(sizeof(t_philo) * data->nums_philo);
	if (data->philos)
		return (1);
	return (0);
}

static void	mutex(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nums_philo)
	{
		mutex_mode(&data->forks[i], INIT_MUTEX, data);
		i++;
	}
	mutex_mode(&data->print, INIT_MUTEX, data);
	mutex_mode(&data->lock, INIT_MUTEX, data);
	mutex_mode(&data->stop_lock, INIT_MUTEX, data);
}

void	data_init(t_data *data, char *argv[], int argc)
{
	data->nums_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (data->time_die < MIN_TIME || data->time_eat < MIN_TIME
		|| data->time_sleep < MIN_TIME)
		error_exit(EXIT_FAILURE, INVALID_TIME, NULL);
	if (data->nums_philo < MIN_PHILO)
		error_exit(EXIT_FAILURE, INVALID_PHILO, NULL);
	data->dead = false;
	data->min_eat = -1;
	if (argc == 6)
	{
		if (!check_nums(argv[5]) && ft_atoi(argv[5]) < 1)
			error_exit(EXIT_FAILURE, INVALID_INPUT, NULL);
		data->min_eat = ft_atoi(argv[5]);
	}
	if (!allocate(data))
		error_exit(EXIT_FAILURE, MALLOC_FAIL, NULL);
	mutex(data);
}
