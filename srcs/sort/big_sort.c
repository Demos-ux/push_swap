/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:09:28 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/23 22:56:12 by dsisli           ###   ########.fr       */
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

/* Return position in A of the node where b_idx should be inserted above.
   A is in circular-ascending order. We find the smallest index > b_idx.
   If none, b_idx is the new max: target is the minimum node (wrap point). */
static int	ft_find_target(t_node *a, int b_idx)
{
	t_node	*cur;
	int		pos;
	int		target_pos;
	int		best;

	cur = a;
	pos = 0;
	target_pos = 0;
	best = INT_MAX;
	while (cur)
	{
		if (cur->index > b_idx && cur->index < best)
		{
			best = cur->index;
			target_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	if (best != INT_MAX)
		return (target_pos);
	cur = a;
	pos = 0;
	best = INT_MAX;
	while (cur)
	{
		if (cur->index < best)
		{
			best = cur->index;
			target_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (target_pos);
}

static int	ft_imax(int a, int b)
{
	return (a > b ? a : b);
}

static int	ft_imin(int a, int b)
{
	return (a < b ? a : b);
}

static int	ft_calc_cost(int pb_pos, int pa_pos, int sb, int sa)
{
	int	c1;
	int	c2;
	int	c3;
	int	c4;

	c1 = ft_imax(pb_pos, pa_pos);
	c2 = ft_imax(sb - pb_pos, sa - pa_pos);
	c3 = pb_pos + (sa - pa_pos);
	c4 = (sb - pb_pos) + pa_pos;
	return (ft_imin(ft_imin(c1, c2), ft_imin(c3, c4)));
}

/* Execute the cheapest combined move, then pa */
static void	ft_execute(t_node **a, t_node **b, int pb_pos, int pa_pos, int sb, int sa)
{
	int	fb;
	int	fa;
	int	bb;
	int	ba;
	int	c1;
	int	c2;
	int	c3;
	int	c4;
	int	best;
	int	common;
	int	rem1;
	int	rem2;

	fb = pb_pos;
	fa = pa_pos;
	bb = sb - pb_pos;
	ba = sa - pa_pos;
	c1 = ft_imax(fb, fa);
	c2 = ft_imax(bb, ba);
	c3 = fb + ba;
	c4 = bb + fa;
	best = ft_imin(ft_imin(c1, c2), ft_imin(c3, c4));
	if (best == c1)
	{
		common = ft_imin(fb, fa);
		rem1 = fb - common;
		rem2 = fa - common;
		while (common-- > 0)
			rr(a, b);
		while (rem1-- > 0)
			rb(b);
		while (rem2-- > 0)
			ra(a);
	}
	else if (best == c2)
	{
		common = ft_imin(bb, ba);
		rem1 = bb - common;
		rem2 = ba - common;
		while (common-- > 0)
			rrr(a, b);
		while (rem1-- > 0)
			rrb(b);
		while (rem2-- > 0)
			rra(a);
	}
	else if (best == c3)
	{
		while (fb-- > 0)
			rb(b);
		while (ba-- > 0)
			rra(a);
	}
	else
	{
		while (bb-- > 0)
			rrb(b);
		while (fa-- > 0)
			ra(a);
	}
	pa(a, b);
}

static void	ft_push_back(t_node **a, t_node **b)
{
	t_node	*cur;
	int		sa;
	int		sb;
	int		pos_b;
	int		best_pb;
	int		best_pa;
	int		best_cost;
	int		cost;
	int		pos_a;
	int		pos_min;

	while (*b)
	{
		if (!*a)
		{
			pa(a, b);
			continue ;
		}
		sa = ft_stacksize(*a);
		sb = ft_stacksize(*b);
		cur = *b;
		pos_b = 0;
		best_cost = INT_MAX;
		best_pb = 0;
		best_pa = 0;
		while (cur)
		{
			pos_a = ft_find_target(*a, cur->index);
			cost = ft_calc_cost(pos_b, pos_a, sb, sa);
			if (cost < best_cost)
			{
				best_cost = cost;
				best_pb = pos_b;
				best_pa = pos_a;
			}
			pos_b++;
			cur = cur->next;
		}
		ft_execute(a, b, best_pb, best_pa, sb, sa);
	}
	/* Final alignment: rotate A so that index 0 is on top */
	sa = ft_stacksize(*a);
	cur = *a;
	pos_min = 0;
	while (cur && cur->index != 0)
	{
		pos_min++;
		cur = cur->next;
	}
	if (pos_min <= sa / 2)
		while (pos_min-- > 0)
			ra(a);
	else
	{
		pos_min = sa - pos_min;
		while (pos_min-- > 0)
			rra(a);
	}
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
