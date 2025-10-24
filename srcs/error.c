
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnnya <nnnya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:21:38 by nnnya             #+#    #+#             */
/*   Updated: 2025/10/17 19:08:48 by nnnya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    exit_cleanly_error(t_stack *a, t_stack *b)
{
    write(STDERR_FILENO, "Error\n", 6);
    exit_cleanly(a, b, FAILURE);
}

void    exit_cleanly(t_stack *a, t_stack *b, int status)
{
	if (a && a->vec)
		free(a->vec);
	if (b && b->vec)
		free(b->vec);
	exit(status);
}