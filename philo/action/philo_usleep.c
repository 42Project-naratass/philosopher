/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_usleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42Bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 22:56:03 by naratass          #+#    #+#             */
/*   Updated: 2026/09/03 22:56:06 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_usleep(t_data *data, size_t time)
{
	size_t	wake_time;

	wake_time = get_time() + time;
	while (get_time() < wake_time)
	{
		if (simulate_stop(data) == true)
			break ;
		usleep(100);
	}
}
