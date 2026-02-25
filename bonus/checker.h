/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:18:51 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/25 22:36:12 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "get_next_line.h"

typedef struct s_op
{
	char	*name;
	void	(*func)(t_node **, t_node **);
}	t_op;

extern const t_op	g_ops[];

void	ft_execute_instruction(t_node **a, t_node **b, char *line);
void	wrap_sa(t_node **a, t_node **b);
void	wrap_sb(t_node **a, t_node **b);
void	wrap_ss(t_node **a, t_node **b);
void	wrap_pa(t_node **a, t_node **b);
void	wrap_pb(t_node **a, t_node **b);
void	wrap_ra(t_node **a, t_node **b);
void	wrap_rb(t_node **a, t_node **b);
void	wrap_rr(t_node **a, t_node **b);
void	wrap_rra(t_node **a, t_node **b);
void	wrap_rrb(t_node **a, t_node **b);
void	wrap_rrr(t_node **a, t_node **b);

#endif

