/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:37:11 by nnnya             #+#    #+#             */
/*   Updated: 2025/12/09 08:51:12 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	replace_with_rank(t_stack *a, int *to_sort)
{
	int	i;
	int	j;

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
}

void	compress(t_stack *a, t_stack *b)
{
	int	*to_sort;
	int	i;

	if (!a || !b)
		exit_cleanly_error(a, b);
	to_sort = malloc(sizeof(int) * a->size);
	if (!to_sort)
		exit_cleanly_error(a, b);
	i = -1;
	while (++i < a->size)
		to_sort[i] = a->vec[i];
	bubble_sort(to_sort, a->size);
	replace_with_rank(a, to_sort);
	free(to_sort);
}

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
