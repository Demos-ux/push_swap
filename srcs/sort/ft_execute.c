/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:00:00 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/24 21:37:05 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_exec_fwd(t_node **a, t_node **b, t_move mv)
{
	int	shared_steps;
	int	fwd_b;
	int	fwd_a;

	fwd_b = mv.pos_b;
	fwd_a = mv.pos_a;
	shared_steps = ft_imin(fwd_b, fwd_a);
	fwd_b -= shared_steps;
	fwd_a -= shared_steps;
	while (shared_steps-- > 0)
		rr(a, b);
	while (fwd_b-- > 0)
		rb(b);
	while (fwd_a-- > 0)
		ra(a);
}

static void	ft_exec_bwd(t_node **a, t_node **b, t_move mv)
{
	int	shared_steps;
	int	bwd_b;
	int	bwd_a;

	bwd_b = mv.size_b - mv.pos_b;
	bwd_a = mv.size_a - mv.pos_a;
	shared_steps = ft_imin(bwd_b, bwd_a);
	bwd_b -= shared_steps;
	bwd_a -= shared_steps;
	while (shared_steps-- > 0)
		rrr(a, b);
	while (bwd_b-- > 0)
		rrb(b);
	while (bwd_a-- > 0)
		rra(a);
}

static void	ft_exec_fwd_abwd(t_node **a, t_node **b, t_move mv)
{
	int	fwd_b;
	int	bwd_a;

	fwd_b = mv.pos_b;
	bwd_a = mv.size_a - mv.pos_a;
	while (fwd_b-- > 0)
		rb(b);
	while (bwd_a-- > 0)
		rra(a);
}

static void	ft_exec_bwd_afwd(t_node **a, t_node **b, t_move mv)
{
	int	bwd_b;
	int	fwd_a;

	bwd_b = mv.size_b - mv.pos_b;
	fwd_a = mv.pos_a;
	while (bwd_b-- > 0)
		rrb(b);
	while (fwd_a-- > 0)
		ra(a);
}

void	ft_execute(t_node **a, t_node **b, t_move mv)
{
	int	min_cost;
	int	fwd_b;
	int	bwd_b;

	fwd_b = mv.pos_b;
	bwd_b = mv.size_b - mv.pos_b;
	min_cost = ft_calc_cost(mv);
	if (min_cost == ft_imax(fwd_b, mv.pos_a))
		ft_exec_fwd(a, b, mv);
	else if (min_cost == ft_imax(bwd_b, mv.size_a - mv.pos_a))
		ft_exec_bwd(a, b, mv);
	else if (min_cost == fwd_b + (mv.size_a - mv.pos_a))
		ft_exec_fwd_abwd(a, b, mv);
	else
		ft_exec_bwd_afwd(a, b, mv);
	pa(a, b);
}
