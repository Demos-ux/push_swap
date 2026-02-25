/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:06:24 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/23 21:59:54 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_findmin(t_node *head)
{
	t_node	*min;

	min = NULL;
	while (head)
	{
		if (head->index == -1)
		{
			if (!min || head->value < min->value)
				min = head;
		}
		head = head->next;
	}
	return (min);
}

void	ft_assign_index(t_node *a)
{
	int		i;
	int		size;
	t_node	*head;
	t_node	*min;
	t_node	*cur;

	i = 0;
	head = a;
	size = ft_stacksize(a);
	cur = a;
	while (cur)
	{
		cur->index = -1;
		cur = cur->next;
	}
	while (i < size)
	{
		min = ft_findmin(head);
		if (min)
			min->index = i;
		i++;
	}
}
