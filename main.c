/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:08:23 by youchiya          #+#    #+#             */
/*   Updated: 2025/06/26 17:54:33 by youchiya         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		*arr;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	arr = parse_args(argc, argv);
	if (is_sorted(arr, argc - 1))
	{
		free(arr);
		return (0);
	}
	init_stacks(&stack_a, &stack_b, arr, argc - 1);
	if ((argc - 1) <= 5)
		sort_small(stack_a, stack_b);
	else
	{
		coord_compression(arr, argc - 1);
		radix_sort(stack_a, stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	free(arr);
	return (0);
}
