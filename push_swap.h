/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:08:55 by youchiya          #+#    #+#             */
/*   Updated: 2025/06/26 01:07:08 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

int				ft_atoi(const char *nptr, int *error);
t_stack			*init_stack(int *arr, int size);
void			free_stack(t_stack *stack);
void			radix_sort(t_stack *stack_a, t_stack *stack_b);
void			pa(t_stack *stack_a, t_stack *stack_b);
void			pb(t_stack *stack_a, t_stack *stack_b);
void			ra(t_stack *stack_a);
void			error_exit(void);
int				is_duplicate(int *arr, int size);
int				is_sorted(int *arr, int size);
void			coord_compression(int *arr, int size);

#endif
