/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:48:07 by nnnya             #+#    #+#             */
/*   Updated: 2025/12/09 10:05:26 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/Libft01/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0
# define POSITIVE 1
# define NEGATIVE -1

typedef struct s_stack
{
	int	*vec;
	int	size;
}		t_stack;

// src/commands

// srcs/chunk_sort.c
void	chunk_sort(t_stack *a, t_stack *b);

// srcs/chunk_utils.c
int		calc_chunk_count(int size);
int		find_b_max(t_stack *b);
void	bring_b_max_top(t_stack *b);

// srcs/commands.c
void	op_sa(t_stack *a);
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);

// srcs/commands_rotate.c
void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);

// srcs/error.c
void	exit_cleanly_error(t_stack *a, t_stack *b);
void	exit_cleanly(t_stack *a, t_stack *b, int status);

// srcs/init.c
void	set_stacks(t_stack *a, t_stack *b, int ac, const char **av);
int		is_int_num(const char *nptr);
int		ps_atoi(const char *nptr);
int		has_dup_elem(t_stack stack);

// srcs/sort_elements.c
void	sort_elements(t_stack *a, t_stack *b);
void	compress(t_stack *a, t_stack *b);

// srcs/sort_utils.c
void	bubble_sort(int *arr, int size);
int		is_sorted(t_stack stack);

// srcs/sort_small.c
void	sort_3(t_stack *a, t_stack *b);
int		get_min_idx(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

#endif
