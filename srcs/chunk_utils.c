/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 08:25:38 by smurayam          #+#    #+#             */
/*   Updated: 2025/12/09 08:27:05 by smurayam         ###   ########.fr       */
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
