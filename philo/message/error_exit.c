/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42Bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 23:07:55 by naratass          #+#    #+#             */
/*   Updated: 2026/09/03 23:07:56 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error_exit(int exit_code, char *msg, t_data *data)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	if (data)
		clear_data(data);
	exit(exit_code);
}
