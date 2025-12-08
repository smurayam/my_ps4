/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:45:01 by nnnya             #+#    #+#             */
/*   Updated: 2025/12/09 08:11:04 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	a.vec = NULL;
	b.vec = NULL;
	if (ac < 2)
		return (0);
	set_stacks(&a, &b, ac, (const char **)av);
	sort_elements(&a, &b);
	exit_cleanly(&a, &b, SUCCESS);
}
