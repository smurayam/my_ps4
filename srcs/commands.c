/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnnya <nnnya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:42:47 by nnnya             #+#    #+#             */
/*   Updated: 2025/10/17 18:02:56 by nnnya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    op_sa(t_stack *a)
{
    int tmp;
    
    if(a->size < 2)
        return;
    tmp = a->vec[0];
    a->vec[0] = a->vec[1];
    a->vec[1] = tmp;
    ft_printf("sa\n");
}

void    op_pa(t_stack *a, t_stack *b)
{
	ssize_t	i;

	if (b->size == 0)
		return ;
	if (a->size != 0)
	{
		i = a->size;
		while (i > 0)
        {
            a->vec[i] = a->vec[i - 1];
            i --;
        }
	}
	a->vec[0] = b->vec[0];
	a->size++;
	i = -1;
	while (++i < b->size - 1)
		b->vec[i] = b->vec[i + 1];
	b->size--;
	ft_printf("pa\n");
}

void	op_pb(t_stack *a, t_stack *b)
{
	ssize_t	i;

	if (a->size == 0)
		return ;
	if (b->size != 0)
	{
		i = b->size;
		while (i > 0)
        {
            b->vec[i] = b->vec[i - 1];
            i--;
        }
    }
	b->vec[0] = a->vec[0];
	b->size++;
	i = -1;
	while (++i < a->size - 1)
		a->vec[i] = a->vec[i + 1];
	a->size--;
	ft_printf("pb\n");
}

void    op_ra(t_stack *a)
{
    int temp;
    ssize_t i;

    if(a->size < 2)
		return;
	temp = a->vec[0];
	i = -1;
	while(++i < a->size - 1)
		a->vec[i] = a->vec[i + 1];
	a->vec[i] = temp;
	ft_printf("ra\n");
}

void	op_rra(t_stack *a)
{
	int	temp;
	ssize_t i;

	if(a->size < 2)
		return;
	temp = a->vec[a->size - 1];
	i = a->size - 1;
	while(--i >= 0)
		a->vec[i + 1] = a->vec[i];
	a->vec[0] = temp;
	ft_printf("rra\n");
}