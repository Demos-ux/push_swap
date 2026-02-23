/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:22:20 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/23 19:25:17 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	ft_small_sort(t_node	*stack)
{
	t_node	two;
	t_node	three;

	two = *stack->next;
	three = *stack->next->next;
	while(stack->next)
	{
		if(stack->value > &two)
			if(&two > &three)
			{
				ra(&*stack);
			}
			else
				rra(&*stack);
		else
			sa(&*stack);
		stack=stack->next;
	}
}
