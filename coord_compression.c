/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_compression.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:08:23 by youchiya          #+#    #+#             */
/*   Updated: 2025/06/26 01:12:01 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	allocate_memory(int **sorted, int **compressed, int size, int *arr)
{
	*sorted = (int *)malloc(sizeof(int) * size);
	*compressed = (int *)malloc(sizeof(int) * size);
	if (!*sorted || !*compressed)
	{
		free(arr);
		if (*sorted)
			free(*sorted);
		if (*compressed)
			free(*compressed);
		error_exit();
	}
}

static void	copy_and_sort(int *arr, int *sorted_arr, int size)
{
	int	i;

	i = 0;
	while (++i < size)
	{
		sorted_arr[i] = arr[i];
		i++;
	}
	sort_array(sorted_arr, size);
}

static void	compress_array(int *arr, int *sorted, int *compressed, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == sorted[j])
			{
				compressed[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	coord_compression(int *arr, int size)
{
	int	*sorted_arr;
	int	*compressed_arr;
	int	i;

	allocate_memory(&sorted_arr, &compressed_arr, size, arr);
	copy_and_sort(arr, sorted_arr, size);
	compress_array(arr, sorted_arr, compressed_arr, size);
	i = 0;
	while (i < size)
	{
		arr[i] = compressed_arr[i];
		i++;
	}
	free(sorted_arr);
	free(compressed_arr);
}
