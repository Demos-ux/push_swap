/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigsort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:00:00 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/24 00:20:23 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max_pos(t_node *cur)
{
	int	pos;
	int	max_pos;
	int	max_idx;

	pos = 0;
	max_pos = 0;
	max_idx = cur->index;
	while (cur)
	{
		if (cur->index > max_idx)
		{
			max_idx = cur->index;
			max_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (max_pos);
}

int	ft_get_chunk_size(int size)
{
	if (size <= 100)
		return (26);
	return (55);
}

void	ft_rotate_b_to_top(t_node **b, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
}

int	ft_imax(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_imin(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
