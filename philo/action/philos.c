/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42Bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 22:56:57 by naratass          #+#    #+#             */
/*   Updated: 2026/09/03 22:56:58 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philos(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (simulate_stop(philo->data) == false)
		routine(philo);
	pthread_exit(0);
}
