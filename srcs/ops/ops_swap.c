/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:00:00 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/24 20:14:27 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *stack)
{
	int	temp_val;
	int	temp_idx;

	if (!stack || !stack->next)
		return ;
	temp_val = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp_val;
	temp_idx = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp_idx;
}

void	sa(t_node *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_node *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_node *a, t_node *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
