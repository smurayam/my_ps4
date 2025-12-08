/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:06:01 by nnnya             #+#    #+#             */
/*   Updated: 2025/12/09 08:10:53 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_stacks(t_stack *a, t_stack *b, int ac, const char **av)
{
	ssize_t	i;

	if (!a || !b || !av)
		exit_cleanly_error(a, b);
	a->vec = malloc(sizeof(int) * (ac - 1));
	a->size = ac - 1;
	b->vec = malloc(sizeof(int) * (ac - 1));
	b->size = 0;
	if (!a->vec || !b->vec)
		exit_cleanly_error(a, b);
	i = -1;
	while (++i < a->size)
	{
		if (!av[i + 1] || is_int_num(av[i + 1]) == FALSE)
			exit_cleanly_error(a, b);
		a->vec[i] = ps_atoi(av[i + 1]);
	}
	if (has_dup_elem(*a) == TRUE)
		exit_cleanly_error(a, b);
}

int	is_int_num(const char *nptr)
{
	long	num;
	int		sign;
	size_t	i;

	sign = 1;
	num = 0;
	i = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
			sign *= -1;
	}
	if (nptr[i] == '\0')
		return (FALSE);
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - '0';
		if (sign == POSITIVE && num > INT_MAX)
			return (FALSE);
		if (sign == NEGATIVE && num > (long)-1 * INT_MIN)
			return (FALSE);
		i++;
	}
	if (nptr[i] != '\0')
		return (FALSE);
	return (TRUE);
}

int	ps_atoi(const char *nptr)
{
	long	num;
	int		sign;
	size_t	i;

	sign = 1;
	num = 0;
	i = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
			sign *= -1;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - '0';
		i++;
	}
	return ((int)sign * num);
}

int	has_dup_elem(t_stack stack)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	while (++i < stack.size)
	{
		j = i;
		while (++j < stack.size)
		{
			if (stack.vec[i] == stack.vec[j])
				return (TRUE);
		}
	}
	return (FALSE);
}
