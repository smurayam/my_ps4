/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:32:06 by smurayam          #+#    #+#             */
/*   Updated: 2025/12/09 10:32:23 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	is_sorted(t_stack stack)
{
	int		temp;
	ssize_t	i;

	if (!stack.vec)
		return (FALSE);
	temp = stack.vec[0];
	i = 0;
	while (++i < stack.size)
	{
		if (stack.vec[i] <= temp)
			return (FALSE);
		temp = stack.vec[i];
	}
	return (TRUE);
}
