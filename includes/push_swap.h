/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnnya <nnnya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:48:07 by nnnya             #+#    #+#             */
/*   Updated: 2025/12/07 18:59:18 by nnnya            ###   ########.fr       */
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
	int		*vec;
	int		size;
}			t_stack;

// src/commands

// src
// chunk_sort.c
static int	calc_chunk_count(int size);
static int	find_b_max(t_stack *b);
static void	bring_b_max_top(t_stack *b);
static void	push_current_chunk(t_stack *a, t_stack *b, int lower, int upper);
void		chunk_sort(t_stack *a, t_stack *b);

// commands.c
void		op_sa(t_stack *a);
void		op_pa(t_stack *a, t_stack *b);
void		op_pb(t_stack *a, t_stack *b);
void		op_ra(t_stack *a);
void		op_rra(t_stack *a);

// src/error.c
void		exit_cleanly_error(t_stack *a, t_stack *b);
void		exit_cleanly(t_stack *a, t_stack *b, int status);

// init.c
void		set_stacks(t_stack *a, t_stack *b, int ac, const char **av);
int			is_int_num(const char *nptr);
int			ps_atoi(const char *nptr);
int			has_dup_elem(t_stack stack);

// main.c
void		op_rra(t_stack *a);

// sort_elements.c
void		sort_elements(t_stack *a, t_stack *b);
void		compress(t_stack *a, t_stack *b);
void		bubble_sort(int *arr, int size);
int			compare_arrays(int *arr1, int *arr2, int *arr3, int size);
int			is_sorted(t_stack stack);

// sort_small.c
void		sort_3(t_stack *a, t_stack *b);
int			get_min_idx(t_stack *a);
void		sort_4(t_stack *a, t_stack *b);
void		sort_5(t_stack *a, t_stack *b);

#endif