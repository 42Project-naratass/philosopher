#include "philo.h"

bool	check_nums(char *str)
{
	if (!str)
		return (false);
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (false);
	}
	return (true);
}
