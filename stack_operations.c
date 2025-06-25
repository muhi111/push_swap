/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:07:59 by youchiya          #+#    #+#             */
/*   Updated: 2025/06/26 00:08:01 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

static t_stack	*populate_stack(t_stack *stack, int *arr, int size)
{
	int		i;
	t_node	*new_node;

	i = size - 1;
	while (i >= 0)
	{
		new_node = create_node(arr[i]);
		if (!new_node)
		{
			free_stack(stack);
			return (NULL);
		}
		new_node->next = stack->top;
		stack->top = new_node;
		stack->size++;
		i--;
	}
	return (stack);
}

t_stack	*init_stack(int *arr, int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	if (!arr)
		return (stack);
	return (populate_stack(stack, arr, size));
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
