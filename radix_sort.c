/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:08:11 by youchiya          #+#    #+#             */
/*   Updated: 2025/06/26 00:08:13 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = stack_a->size;
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack_a->top->value >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
