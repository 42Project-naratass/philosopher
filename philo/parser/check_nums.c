#include "../includes/philo.h"

bool	check_nums(char *str)
{
	if (!(*str))
		return (false);
	if (*str == '+')
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
