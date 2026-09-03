/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42Bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 22:56:37 by naratass          #+#    #+#             */
/*   Updated: 2026/09/03 22:56:39 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(philo->fork1);
	print_status(philo, GET_FORK_1);
	usleep(philo->data->time_die * 1000);
	print_status(philo, DIED);
	pthread_mutex_unlock(philo->fork1);
	pthread_exit(0);
}
