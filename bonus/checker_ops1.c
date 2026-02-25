/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:18:51 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/24 22:18:51 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	wrap_sa(t_node **a, t_node **b)
{
	(void)b;
	sa(*a);
}

void	wrap_sb(t_node **a, t_node **b)
{
	(void)a;
	sb(*b);
}

void	wrap_ss(t_node **a, t_node **b)
{
	ss(*a, *b);
}

void	wrap_pa(t_node **a, t_node **b)
{
	pa(a, b);
}

void	wrap_pb(t_node **a, t_node **b)
{
	pb(a, b);
}
