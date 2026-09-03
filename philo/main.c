/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42Bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 22:06:48 by naratass          #+#    #+#             */
/*   Updated: 2026/09/03 22:08:06 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	input_checker(char *argv[])
{
	if (!check_nums(argv[1]) || !check_nums(argv[2])
		|| !check_nums(argv[3]) || !check_nums(argv[4]))
		error_exit(EXIT_FAILURE, INVALID_INPUT, NULL);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 5 && argc != 6)
		error_exit(EXIT_FAILURE, INVALID_USAGE, NULL);
	input_checker(argv);
	data_init(&data, argv, argc);
	philo_simulate(&data);
	return (0);
}
