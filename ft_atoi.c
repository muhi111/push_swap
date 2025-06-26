/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya@student.42tokyo.jp <youchiya>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:16:53 by youchiya          #+#    #+#             */
/*   Updated: 2025/06/26 16:17:05 by youchiya@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_over_and_underflow(long long result, int sign)
{
	if (sign == 1)
	{
		if (result > INT_MAX)
			return (true);
	}
	else
	{
		if (result > ((long long)INT_MIN * -1))
			return (true);
	}
	return (false);
}

static long long	parse_digits(const char **nptr, int sign, int *error)
{
	long long	result;

	result = 0;
	while (**nptr >= '0' && **nptr <= '9')
	{
		result = result * 10 + (**nptr - '0');
		if (is_over_and_underflow(result, sign))
		{
			*error = 1;
			return (0);
		}
		(*nptr)++;
	}
	return (result);
}

int	ft_atoi(const char *nptr, int *error)
{
	int			sign;
	long long	result;

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
