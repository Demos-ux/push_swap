/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:22:20 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/23 22:07:57 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort3(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second > third)
	{
		sa(*a);
		rra(a);
	}
	else if (first > second && first > third)
		ra(a);
	else if (second > third && first < third)
	{
		sa(*a);
		ra(a);
	}
	else if (second > first && second > third)
		rra(a);
	else if (first > second)
		sa(*a);
}

static void	insert_sorted(t_node **a, t_node **b)
{
	int	size;
	int	rotations;
	int	target;

	target = (*b)->index;
	size = ft_stacksize(*a);
	rotations = 0;
	while (rotations < size && (*a)->index < target)
	{
		ra(a);
		rotations++;
	}
	pa(a, b);
	while (rotations-- > 0)
		rra(a);
}

void	ft_smallsort(t_node **a, t_node **b)
{
	int	size;

	size = ft_stacksize(*a);
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(*a);
		return ;
	}
	if (size >= 4)
		pb(a, b);
	if (size == 5)
		pb(a, b);
	sort3(a);
	while (*b)
		insert_sorted(a, b);
}
