/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:08:23 by youchiya          #+#    #+#             */
/*   Updated: 2025/06/26 18:25:22 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*parse_args(int argc, char **argv)
{
	int	*arr;
	int	i;
	int	error;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!arr)
		error_exit();
	i = 0;
	error = 0;
	while (i < argc - 1)
	{
		arr[i] = ft_atoi(argv[i + 1], &error);
		if (error)
		{
			free(arr);
			error_exit();
		}
		i++;
	}
	if (is_duplicate(arr, argc - 1))
	{
		free(arr);
		error_exit();
	}
	return (arr);
}

static void	init_stacks(t_stack **a, t_stack **b, int *arr, int size)
{
	*a = init_stack(arr, size);
	if (!*a)
	{
		free(arr);
		error_exit();
	}
	*b = init_stack(NULL, 0);
	if (!*b)
	{
		free_stack(*a);
		free(arr);
		error_exit();
	}
}

static void	sort(int *arr, int size)
{
	t_stack	*a;
	t_stack	*b;

	if (size <= 5)
	{
		init_stacks(&a, &b, arr, size);
		sort_small(a, b);
	}
	else
	{
		coord_compression(arr, size);
		init_stacks(&a, &b, arr, size);
		radix_sort(a, b);
	}
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	int		*arr;

	if (argc < 2)
		return (0);
	arr = parse_args(argc, argv);
	if (is_sorted(arr, argc - 1))
	{
		free(arr);
		return (0);
	}
	sort(arr, argc - 1);
	free(arr);
	return (0);
}
