/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_stop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42Bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 22:55:23 by naratass          #+#    #+#             */
/*   Updated: 2026/09/04 23:31:41 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	simulate_stop(t_data *data)
{
	mutex_mode(&data->lock, LOCK_MUTEX, data);
	if (data->dead == true)
	{
		mutex_mode(&data->lock, UNLOCK_MUTEX, data);
		return (true);
	}
	pthread_mutex_unlock(&data->lock);
	return (false);
}
