/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 08:28:19 by smurayam          #+#    #+#             */
/*   Updated: 2025/12/09 08:29:17 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_ra(t_stack *a)
{
	int		temp;
	ssize_t	i;

	if (a->size < 2)
		return ;
	temp = a->vec[0];
	i = -1;
	while (++i < a->size - 1)
		a->vec[i] = a->vec[i + 1];
	a->vec[i] = temp;
	ft_printf("ra\n");
}

void	op_rb(t_stack *b)
{
	int		temp;
	ssize_t	i;

	if (b->size < 2)
		return ;
	temp = b->vec[0];
	i = -1;
	while (++i < b->size - 1)
		b->vec[i] = b->vec[i + 1];
	b->vec[i] = temp;
	ft_printf("rb\n");
}

void	op_rra(t_stack *a)
{
	int		temp;
	ssize_t	i;

	if (a->size < 2)
		return ;
	temp = a->vec[a->size - 1];
	i = a->size - 1;
	while (--i >= 0)
		a->vec[i + 1] = a->vec[i];
	a->vec[0] = temp;
	ft_printf("rra\n");
}

void	op_rrb(t_stack *b)
{
	int		temp;
	ssize_t	i;

	if (b->size < 2)
		return ;
	temp = b->vec[b->size - 1];
	i = b->size - 1;
	while (--i >= 0)
		b->vec[i + 1] = b->vec[i];
	b->vec[0] = temp;
	ft_printf("rrb\n");
}
