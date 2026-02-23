/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:00:00 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/24 00:26:21 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_exec_fwd(t_node **a, t_node **b, t_move mv)
{
	int	common;
	int	fb;
	int	fa;

	fb = mv.pb;
	fa = mv.pa;
	common = ft_imin(fb, fa);
	fb -= common;
	fa -= common;
	while (common-- > 0)
		rr(a, b);
	while (fb-- > 0)
		rb(b);
	while (fa-- > 0)
		ra(a);
}

static void	ft_exec_bwd(t_node **a, t_node **b, t_move mv)
{
	int	common;
	int	bb;
	int	ba;

	bb = mv.sb - mv.pb;
	ba = mv.sa - mv.pa;
	common = ft_imin(bb, ba);
	bb -= common;
	ba -= common;
	while (common-- > 0)
		rrr(a, b);
	while (bb-- > 0)
		rrb(b);
	while (ba-- > 0)
		rra(a);
}

static void	ft_exec_fwd_abwd(t_node **a, t_node **b, t_move mv)
{
	int	fb;
	int	ba;

	fb = mv.pb;
	ba = mv.sa - mv.pa;
	while (fb-- > 0)
		rb(b);
	while (ba-- > 0)
		rra(a);
}

static void	ft_exec_bwd_afwd(t_node **a, t_node **b, t_move mv)
{
	int	bb;
	int	fa;

	bb = mv.sb - mv.pb;
	fa = mv.pa;
	while (bb-- > 0)
		rrb(b);
	while (fa-- > 0)
		ra(a);
}

void	ft_execute(t_node **a, t_node **b, t_move mv)
{
	int	best;
	int	fb;
	int	bb;

	fb = mv.pb;
	bb = mv.sb - mv.pb;
	best = ft_calc_cost(mv);
	if (best == ft_imax(fb, mv.pa))
		ft_exec_fwd(a, b, mv);
	else if (best == ft_imax(bb, mv.sa - mv.pa))
		ft_exec_bwd(a, b, mv);
	else if (best == fb + (mv.sa - mv.pa))
		ft_exec_fwd_abwd(a, b, mv);
	else
		ft_exec_bwd_afwd(a, b, mv);
	pa(a, b);
}
