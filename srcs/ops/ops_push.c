/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:00:00 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/24 20:14:27 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dst)
{
	t_node	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = temp->next;
	temp->next = *dst;
	*dst = temp;
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pb\n");
}
