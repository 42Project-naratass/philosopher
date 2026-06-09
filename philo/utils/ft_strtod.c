#include "philo.h"

static bool	is_inf(char *p, char **endptr)
{
	if ((p[0] == 'i' || p[0] == 'I')
		&& (p[1] == 'n' || p[1] == 'N')
		&& (p[2] == 'f' || p[2] == 'F'))
	{
		if ((p[3] == 'i' || p[3] == 'I')
			&& (p[4] == 'n' || p[4] == 'N')
			&& (p[5] == 'i' || p[5] == 'I')
			&& (p[6] == 't' || p[6] == 'T')
			&& (p[7] == 'y' || p[7] == 'Y'))
		{
			*endptr = p + 8;
		}
		else
			*endptr = p + 3;
		return (true);
	}
	return (false);
}

static bool	is_nan(char *p, char **endptr)
{
	if ((p[0] == 'n' || p[0] == 'N')
		&& (p[1] == 'a' || p[1] == 'A')
		&& (p[2] == 'n' || p[2] == 'N'))
	{
		p += 3;
		if (*p == '(')
		{
			++p;
			while (*p != '\0' && *p != ')')
				++p;
			if (*p == ')')
				++p;
		}
		*endptr = p;
		return (true);
	}
	return (false);
}

static bool	apply_e(char *p, char **endptr)
{
	int	i;

	if (*p == 'e' || *p == 'E')
	{
		i = 1;
		if (p[i] == '+' || p[i] == '-')
			++i;
		if (is_digit(p[i]))
		{
			while (is_digit(p[i]))
				++i;
			*endptr = p + i;
			return (true);
		}
	}
	return (false);
}

static bool	still_digit(char *p, char **endptr)
{
	int	got_dot;

	if (is_digit(*p) || *p == '.')
	{
		got_dot = 0;
		while (is_digit(*p) || (!got_dot && *p == '.'))
		{
			if (*p == '.')
				got_dot = 1;
			++p;
		}
		if (apply_e(p, endptr))
			return (true);
		*endptr = p;
		return (true);
	}
	return (false);
}

double	ft_strtod(char *str, char **endptr)
{
	char	*p;

	if (endptr == NULL)
		return (atof(str));
	p = str;
	while (is_space(*p))
		p++;
	if (*p == '+' || *p == '-')
		p++;
	if (is_inf(p, endptr))
		return (atof(str));
	if (is_nan(p, endptr))
		return (atof(str));
	if (still_digit(p, endptr))
		return (atof(str));
	*endptr = str;
	return (0.0);
}
