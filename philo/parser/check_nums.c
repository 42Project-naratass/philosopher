#include "../includes/philo.h"

bool	check_nums(char *str)
{
	if (!(*str))
		return (false);
	if (*str != '+')
		error_exit(EXIT_FAILURE, NOT_POSITIVE, NULL);
	str++;
	if (!(*str))
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}
