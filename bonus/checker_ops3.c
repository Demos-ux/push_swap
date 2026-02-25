/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:18:51 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/24 22:18:51 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	wrap_rrr(t_node **a, t_node **b)
{
	rrr(a, b);
}

const t_op	g_ops[] = {
	{"sa", wrap_sa},
	{"sb", wrap_sb},
	{"ss", wrap_ss},
	{"pa", wrap_pa},
	{"pb", wrap_pb},
	{"ra", wrap_ra},
	{"rb", wrap_rb},
	{"rr", wrap_rr},
	{"rra", wrap_rra},
	{"rrb", wrap_rrb},
	{"rrr", wrap_rrr},
	{NULL, NULL}
};
