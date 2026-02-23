/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:17:54 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/24 00:13:51 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_freetokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

t_node	*ft_init_stack(int argc, char **argv)
{
	t_node	*a;
	char	**tokens;

	a = NULL;
	if (argc <= 1)
		exit(0);
	if (argc == 2)
		tokens = ft_split(argv[1], ' ');
	else
		tokens = argv + 1;
	if (!tokens)
		ft_error();
	if (ft_checktoken(tokens))
	{
		if (argc == 2)
			ft_freetokens(tokens);
		ft_error();
	}
	a = ft_buildstack(tokens);
	if (argc == 2)
		ft_freetokens(tokens);
	if (!a)
		ft_error();
	return (a);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size;

	b = NULL;
	a = ft_init_stack(argc, argv);
	ft_assign_index(a);
	if (ft_issorted(a))
	{
		ft_freelist(a);
		return (0);
	}
	size = ft_stacksize(a);
	if (size <= 5)
		ft_smallsort(&a, &b);
	else
		ft_bigsort(&a, &b);
	ft_freelist(a);
	ft_freelist(b);
	return (0);
}
