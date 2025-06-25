/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:16:53 by youchiya          #+#    #+#             */
/*   Updated: 2025/06/26 00:56:48 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_over_and_underflow(long result, int sign, int next)
{
	if (sign == 1)
	{
		if (result < -1 * (INT_MAX / 10))
			return (true);
		else if (result == -1 * (INT_MAX / 10) && next > INT_MAX % 10)
			return (true);
	}
	else
	{
		if (result < INT_MIN / 10)
			return (true);
		else if (result == INT_MIN / 10 && next > -1 * (INT_MIN % 10))
			return (true);
	}
	return (false);
}

static long	parse_digits(const char **nptr, int sign, int *error)
{
	long	result;

	result = 0;
	while (**nptr >= '0' && **nptr <= '9')
	{
		if (is_over_and_underflow(result, sign, **nptr - '0'))
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + (**nptr - '0');
		(*nptr)++;
	}
	return (result);
}

int	ft_atoi(const char *nptr, int *error)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (*nptr == '\0')
		*error = 1;
	result = parse_digits(&nptr, sign, error);
	if (*nptr != '\0')
		*error = 1;
	return ((int)(result * sign));
}
