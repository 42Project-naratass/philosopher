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

# define INVALID_INPUT "Error: Invalid input.\n"
# define INVALID_PHILO "Error: Philo nums can't be less than 1.\n"
# define NOT_POSITIVE "Error: Can't be negative value.\n"
# define HELP "Invalid usage: ./philo <1 - 500>\fnums_philo <"
# define MALLOC_FAIL "Error: Memory allocation failed.\n" 
# define THREAD_CREATE_FAIL "Error: Thread creation failed.\n"
# define THREAD_JOIN_FAIL "Error: Thread join failed.\n"
# define LOCK_FAIL "Error: Mutex lock failed.\n"  
# define UNLOCK_FAIL "Error: Mutex unlock failed.\n"
# define MUTEX_INIT_FAIL "Error: Mutex init failed.\n"
# define MUTEX_DESTROY_FAIL "Error: Mutex destroy failed.\n"
# define TIME_FAIL "Error: Get time failed.\n"
# define INIT_FORK_PHILO_FAIL "Error: Philo init fork fail.\n"

#endif
