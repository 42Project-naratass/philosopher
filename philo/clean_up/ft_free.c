/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 22:58:11 by naratass          #+#    #+#             */
/*   Updated: 2026/09/03 23:00:40 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_free(t_data *data)
{
	if (data->tid)
		free(data->tid);
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
}
