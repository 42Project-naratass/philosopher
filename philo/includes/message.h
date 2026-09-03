/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42Bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 23:01:46 by naratass          #+#    #+#             */
/*   Updated: 2026/09/03 23:01:49 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

# define RST "\033[0m"  // Reset to default
# define BK "\033[1;30m"  // Black
# define R "\033[1;31m"  // Red
# define G "\033[1;32m"  // Green
# define Y "\033[1;33m"  // Yellow
# define BE "\033[1;34m"  // Blue
# define M "\033[1;35m"  // Magenta
# define C "\033[1;36m"  // Cyan
# define W "\033[1;37m"  // White

# define INVALID_INPUT "Invalid input: Invalid input.\n"
# define INVALID_PHILO "Invalid input: Philo nums can't be less than 1.\n"
# define NOT_POSITIVE "Invalid input: Can't be negative value.\n"
# define INVALID_USAGE "Invalid usage: ./philo <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n"
# define INVALID_TIME "Invalid input: Time can't be less than 60ms.\n"
# define MALLOC_FAIL "Error: Memory allocation failed.\n" 
# define THREAD_CREATE_FAIL "Error: Thread creation failed.\n"
# define THREAD_JOIN_FAIL "Error: Thread join failed.\n"
# define LOCK_FAIL "Error: Mutex lock failed.\n"  
# define UNLOCK_FAIL "Error: Mutex unlock failed.\n"
# define MUTEX_INIT_FAIL "Error: Mutex init failed.\n"
# define MUTEX_DESTROY_FAIL "Error: Mutex destroy failed.\n"
# define TIME_FAIL "Error: Get time failed.\n"
# define INIT_FORK_PHILO_FAIL "Error: Philo init fork fail.\n"
# define INIT_PHILO_FAIL "Error: Philo faile to init.\n"

#endif
