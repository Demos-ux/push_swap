/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:18:51 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/24 22:18:51 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	wrap_ra(t_node **a, t_node **b)
{
	(void)b;
	ra(a);
}

void	wrap_rb(t_node **a, t_node **b)
{
	(void)a;
	rb(b);
}

void	wrap_rr(t_node **a, t_node **b)
{
	rr(a, b);
}

void	wrap_rra(t_node **a, t_node **b)
{
	(void)b;
	rra(a);
}

void	wrap_rrb(t_node **a, t_node **b)
{
	(void)a;
	rrb(b);
}
