/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42Bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 23:08:41 by naratass          #+#    #+#             */
/*   Updated: 2026/09/03 23:11:18 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	check_nums(char *str)
{
	if (!str || !(*str))
		return (false);
	if (*str == '-')
		error_exit(EXIT_FAILURE, NOT_POSITIVE, NULL);
	else if (*str == '+')
	{
		str++;
		if (!(*str))
			error_exit(EXIT_FAILURE, NOT_POSITIVE, NULL);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}
