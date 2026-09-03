/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42Bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 22:57:03 by naratass          #+#    #+#             */
/*   Updated: 2026/09/03 22:57:04 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	routine(t_philo *philo)
{
	mutex_mode(philo->fork1, LOCK_MUTEX, philo->data);
	print_status(philo, GET_FORK_1);
	mutex_mode(philo->fork_2, LOCK_MUTEX, philo->data);
	print_status(philo, GET_FORK_2);
	print_status(philo, EATING);
	mutex_mode(&philo->data->lock, LOCK_MUTEX, philo->data);
	philo->eating = true;
	mutex_mode(&philo->data->lock, UNLOCK_MUTEX, philo->data);
	usleep(philo->data->time_eat * 1000);
	mutex_mode(philo->fork1, UNLOCK_MUTEX, philo->data);
	mutex_mode(philo->fork_2, UNLOCK_MUTEX, philo->data);
	if (philo->data->min_eat > 0)
		philo->meals_eat++;
	mutex_mode(&philo->data->lock, LOCK_MUTEX, philo->data);
	philo->eating = false;
	philo->last_eat = get_time();
	mutex_mode(&philo->data->lock, UNLOCK_MUTEX, philo->data);
	print_status(philo, SLEEPING);
	usleep(philo->data->time_sleep * 1000);
	print_status(philo, THINKING);
}
