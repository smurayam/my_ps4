/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnnya <nnnya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:48:07 by nnnya             #+#    #+#             */
/*   Updated: 2025/10/01 16:53:23 by nnnya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP;
# define PUSH_SWAP_H;

#include "libft/libft.h"
#include "printf/ft_printf.h"

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0
# define POSITIVE 1
# define NEGATIVE -1

typedef struct s_stack
{
    int *vec;
    int size;
}       t_stack;

//src/commands

//src/utils
void    exit_cleanly_error(t_stack *a, t_stack *b);
void    exit_cleanly(t_stack *a, t_stack *b, int status);

//src
void    set_stacs(t_stack *a, t_stack *b, int ac, const char **av);
int	    is_int_num(const char *nptr);
int     ps_atoi(const char *nptr);
int     has_dup_elem(int *arr, int size, int elem);
void    sort_elements(t_stack *a, t_stack *b);
#endif