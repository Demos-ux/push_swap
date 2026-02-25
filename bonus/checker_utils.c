/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:24:43 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/25 22:37:04 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

void	ft_execute_instruction(t_node **a, t_node **b, char *line)
{
	int	i;

	i = 0;
	while (g_ops[i].name)
	{
		if (!ft_strncmp(line, g_ops[i].name, ft_strlen(g_ops[i].name) + 1))
		{
			g_ops[i].func(a, b);
			return ;
		}
		i++;
	}
}
