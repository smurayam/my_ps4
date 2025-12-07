/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnnya <nnnya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 01:42:23 by nnnya             #+#    #+#             */
/*   Updated: 2025/12/08 02:27:01 by nnnya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	calc_chunk_count(int size)
{
	if (size <= 100)
		return (3);
	return (6);
}

static int	find_b_max(t_stack *b)
{
	int	i;
	int	idx;
	int	max;

	i = 0;
	idx = 0;
	max = b->vec[0];
	while (i < b->size)
	{
		if (b->vec[i] > max)
		{
			max = b->vec[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

static void	bring_b_max_top(t_stack *b)
{
	int	idx;
	int	count;

	idx = find_b_max(b);
	count = idx;
	if (idx <= b->size / 2)
	{
		while (count > 0)
		{
			op_rb(b);
			count--;
		}
	}
	else
	{
		count = b->size - idx;
		while (count > 0)
		{
			op_rrb(b);
			count--;
		}
	}
}

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
	int chunk_count;
	int chunk_size;
	int chunk;
	int lower;
	int upper;
	int size;

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