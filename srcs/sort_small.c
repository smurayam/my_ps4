/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnnya <nnnya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:27:37 by nnnya             #+#    #+#             */
/*   Updated: 2025/12/07 18:59:39 by nnnya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	third;

	first = a->vec[0];
	second = a->vec[1];
	third = a->vec[2];
	if (first < third && third < second)
	{
		op_pb(a, b);
		op_sa(a);
		op_pa(a, b);
	}
	else if (second < first && first < third)
		op_sa(a);
	else if (second < third && third < first)
		op_ra(a);
	else if (third < first && first < second)
		op_rra(a);
	else if (third < second && second < first)
	{
		op_sa(a);
		op_rra(a);
	}
}

int	get_min_idx(t_stack *a)
{
	int	i;
	int	min_idx;

	i = 0;
	min_idx = 0;
	while (++i < a->size)
	{
		if (a->vec[i] < a->vec[min_idx])
			min_idx = i;
	}
	return (min_idx);
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	min_idx;

	min_idx = get_min_idx(a);
	if (min_idx == 1)
		op_ra(a);
	else if (min_idx == 2)
	{
		op_ra(a);
		op_ra(a);
	}
	else if (min_idx == 3)
		op_rra(a);
	op_pb(a, b);
	sort_3(a, b);
	op_pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int min_idx;

	min_idx = get_min_idx(a);
	if (min_idx == 1)
		op_ra(a);
	else if (min_idx == 2)
	{
		op_ra(a);
		op_ra(a);
	}
	else if (min_idx == 3)
	{
		op_rra(a);
		op_rra(a);
	}
	else if (min_idx == 4)
		op_rra(a);
	op_pb(a, b);
	sort_4(a, b);
	op_pa(a, b);
}