/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:09:28 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/24 21:37:04 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_in_chunk(t_node *a, int chunk_min, int chunk_max)
{
	int	count;

	count = 0;
	while (a)
	{
		if (a->index >= chunk_min && a->index <= chunk_max)
			count++;
		a = a->next;
	}
	return (count);
}

static void	ft_push_chunks(t_node **a, t_node **b, int chunk_min, int chunk_max)
{
	int	to_push;
	int	median;

	to_push = ft_count_in_chunk(*a, chunk_min, chunk_max);
	median = (chunk_min + chunk_max) / 2;
	while (to_push > 0)
	{
		if ((*a)->index >= chunk_min && (*a)->index <= chunk_max)
		{
			pb(a, b);
			if ((*b)->index < median)
				rb(b);
			to_push--;
		}
		else
			ra(a);
	}
}

static void	ft_align_a(t_node **a)
{
	int		size_a;
	int		pos_min;
	t_node	*cur;

	size_a = ft_stacksize(*a);
	cur = *a;
	pos_min = 0;
	while (cur && cur->index != 0)
	{
		pos_min++;
		cur = cur->next;
	}
	if (pos_min <= size_a / 2)
		while (pos_min-- > 0)
			ra(a);
	else
	{
		pos_min = size_a - pos_min;
		while (pos_min-- > 0)
			rra(a);
	}
}

static void	ft_push_back(t_node **a, t_node **b)
{
	t_move	mv;

	while (*b)
	{
		if (!*a)
		{
			pa(a, b);
			continue ;
		}
		mv.pos_b = 0;
		mv.pos_a = 0;
		ft_best_pair(a, b, &mv);
		ft_execute(a, b, mv);
	}
	ft_align_a(a);
}

void	ft_bigsort(t_node **a, t_node **b)
{
	int	chunk_size;
	int	chunk_min;
	int	size;

	size = ft_stacksize(*a);
	chunk_size = ft_get_chunk_size(size);
	chunk_min = 0;
	while (chunk_min < size)
	{
		ft_push_chunks(a, b, chunk_min, chunk_min + chunk_size - 1);
		chunk_min += chunk_size;
	}
	ft_push_back(a, b);
}
