/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 01:42:23 by nnnya             #+#    #+#             */
/*   Updated: 2025/12/09 08:27:07 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_current_chunk(t_stack *a, t_stack *b, int lower, int upper)
{
	int	i;
	int	val;
	int	count;

	i = 0;
	count = a->size;
	while (i < count)
	{
		val = a->vec[0];
		if (val >= lower && val < upper)
		{
			op_pb(a, b);
			if (val < (lower + upper) / 2)
				op_rb(b);
			count--;
			i = 0;
		}
		else
		{
			op_ra(a);
			i++;
		}
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk_count;
	int	chunk_size;
	int	chunk;
	int	lower;
	int	upper;
	int	size;

	size = a->size;
	chunk_count = calc_chunk_count(size);
	chunk_size = (size / chunk_count) + (size % chunk_count ? 1 : 0);
	chunk = 0;
	while (chunk < chunk_count)
	{
		lower = chunk * chunk_size;
		upper = lower + chunk_size;
		if (upper > size)
			upper = size;
		push_current_chunk(a, b, lower, upper);
		chunk++;
	}
	while (b->size > 0)
	{
		bring_b_max_top(b);
		op_pa(a, b);
	}
}
