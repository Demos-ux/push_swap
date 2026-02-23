/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:48:03 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/23 22:11:21 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isvalidnbr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_hasdup(char **tokens)
{
	int	i;
	int	j;

	i = 0;
	while (tokens[i])
	{
		j = i + 1;
		while (tokens[j])
		{
			if (ft_atoi(tokens[i]) == ft_atoi(tokens[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_checktoken(char **tokens)
{
	int		i;
	long	nbr;
	char	*endptr;

	i = 0;
	if (!tokens[0])
		return (1);
	while (tokens[i])
	{
		if (!ft_isvalidnbr(tokens[i]))
			return (1);
		nbr = strtol(tokens[i], &endptr, 10);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (1);
		i++;
	}
	if (ft_hasdup(tokens))
		return (1);
	return (0);
}

int	ft_stacksize(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
