/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:06:44 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/23 22:20:35 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_newnode(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_freelist(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

t_node	*ft_buildstack(char **tokens)
{
	int		i;
	t_node	*head;
	t_node	*tail;
	t_node	*node;

	i = 0;
	head = NULL;
	tail = NULL;
	while (tokens[i])
	{
		node = ft_newnode(atoi(tokens[i]));
		if (!node)
		{
			ft_freelist(head);
			return (NULL);
		}
		if (!head)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
		i++;
	}
	return (head);
}
