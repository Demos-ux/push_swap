/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:06:44 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/22 22:09:47 by dsisli           ###   ########.fr       */
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

ft_addnode(t_node head)
{
}
t_node	*ft_buildstack(char **tokens)
{
	int		i;
	t_node	*head;
	t_node	*tail;
	t_node	*node;
	t_node	*tmp;

	i = 0;
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
