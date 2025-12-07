/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnnya <nnnya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:37:11 by nnnya             #+#    #+#             */
/*   Updated: 2025/12/07 23:38:39 by nnnya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_elements(t_stack *a, t_stack *b)
{
	if (is_sorted(*a) == TRUE)
		return ;
	if (a->size == 2)
		op_sa(a);
	else if (a->size == 3)
		sort_3(a, b);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
	{
		compress(a, b);
		chunk_sort(a, b);
	}
}

void	compress(t_stack *a, t_stack *b)
{
	int	*to_sort;
	int	i;
	int	j;

	if (!a || !b)
		exit_cleanly_error(a, b);
	to_sort = malloc(sizeof(int) * a->size);
	if (!to_sort)
		exit_cleanly_error(a, b);
	i = -1;
	while (++i < a->size)
		to_sort[i] = a->vec[i];
	bubble_sort(to_sort, a->size);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->vec[i] == to_sort[j])
			{
				a->vec[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(to_sort);
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	is_sorted(t_stack stack)
{
	int temp;
	ssize_t i;

	if (!stack.vec)
		return (FALSE);
	temp = stack.vec[0];
	i = 0;
	while (++i < stack.size)
	{
		if (stack.vec[i] <= temp)
			return (FALSE);
		temp = stack.vec[i];
	}
	return (TRUE);
}