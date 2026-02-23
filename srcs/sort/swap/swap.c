/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:49:32 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/23 22:23:57 by dsisli           ###   ########.fr       */
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
