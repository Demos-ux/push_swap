/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_target.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:00:00 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/24 00:20:23 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_min_pos(t_node *a)
{
	int	pos;
	int	min_pos;
	int	best;

	pos = 0;
	min_pos = 0;
	best = INT_MAX;
	while (a)
	{
		if (a->index < best)
		{
			best = a->index;
			min_pos = pos;
		}
		pos++;
		a = a->next;
	}
	return (min_pos);
}

static int	ft_find_target(t_node *a, int b_idx)
{
	t_node	*orig;
	int		pos;
	int		res;
	int		best;

	orig = a;
	pos = 0;
	res = 0;
	best = INT_MAX;
	while (a)
	{
		if (a->index > b_idx && a->index < best)
		{
			best = a->index;
			res = pos;
		}
		pos++;
		a = a->next;
	}
	if (best != INT_MAX)
		return (res);
	return (ft_find_min_pos(orig));
}

int	ft_calc_cost(t_move mv)
{
	int	c1;
	int	c2;
	int	c3;
	int	c4;

	c1 = ft_imax(mv.pb, mv.pa);
	c2 = ft_imax(mv.sb - mv.pb, mv.sa - mv.pa);
	c3 = mv.pb + (mv.sa - mv.pa);
	c4 = (mv.sb - mv.pb) + mv.pa;
	return (ft_imin(ft_imin(c1, c2), ft_imin(c3, c4)));
}

static void	ft_update_best(t_move *best_mv, t_move *tmp,
	int *best_cost, int pos_b)
{
	int	cost;

	cost = ft_calc_cost(*tmp);
	if (cost < *best_cost)
	{
		*best_cost = cost;
		best_mv->pb = pos_b;
		best_mv->pa = tmp->pa;
	}
}

void	ft_best_pair(t_node **a, t_node **b, t_move *mv)
{
	t_node	*cur;
	int		pos_b;
	int		best_cost;
	t_move	tmp;

	mv->sb = ft_stacksize(*b);
	mv->sa = ft_stacksize(*a);
	cur = *b;
	pos_b = 0;
	best_cost = INT_MAX;
	while (cur)
	{
		tmp.pb = pos_b;
		tmp.pa = ft_find_target(*a, cur->index);
		tmp.sb = mv->sb;
		tmp.sa = mv->sa;
		ft_update_best(mv, &tmp, &best_cost, pos_b);
		pos_b++;
		cur = cur->next;
	}
}
