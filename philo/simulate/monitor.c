/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42Bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 22:10:09 by naratass          #+#    #+#             */
/*   Updated: 2026/09/03 22:39:19 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_dead(t_philo *philo)
{
	if (philo->eating == false
		&& elapsed_time(philo->last_eat) >= philo->data->time_die)
	{
		philo->data->dead = true;
		pthread_mutex_unlock(&philo->data->lock);
		print_status(philo, DIED);
		return (true);
	}
	return (false);
}

void	monitor(t_data *data)
{
	size_t	i;
	bool	all_full;

	while (true)
	{
		all_full = true;
		i = 0;
		while (i < data->nums_philo)
		{
			pthread_mutex_lock(&data->lock);
			if (is_dead(&data->philos[i]) == true)
				return ;
			if (data->philos[i++].meals_eat < data->min_eat)
				all_full = false;
			pthread_mutex_unlock(&data->lock);
		}
		if (data->min_eat > 0 && all_full == true)
		{
			pthread_mutex_lock(&data->lock);
			data->dead = true;
			mutex_mode(&data->lock, UNLOCK_MUTEX, data);
			pthread_mutex_unlock(&data->lock);
			return ;
		}
	}
}
