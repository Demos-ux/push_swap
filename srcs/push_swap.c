/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:17:54 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/22 22:09:28 by dsisli           ###   ########.fr       */
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
int	main(int argc, char **argv)
{
	char	**tokens;
	t_node	*a;
	t_node	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		tokens = ft_split(argv[1], " ");
		if (!tokens)
			return (0);
	}
	else
		tokens = argv + 1;
	if (ft_checktoken(tokens))
	{
		ft_error();
		ft_freetokens(tokens);
	}
	a = ft_buildstack(tokens);
	if (!a)
		ft_error();
	ft_assign_index(a);
	size = ft_lstsize(a);
	if (ft_issorted(a))
	{
		ft_freelist(a);
		return (0);
	}
	if (size <= 5)
		ft_smallsort(&a, &b);
	else
		ft_bigsort(&a, &b);
	ft_freelist(a);
	ft_freelist(b);
	if (argc == 2)
		ft_freetokens(tokens);
	return (0);
}

/*TODO
DONE:
- ft_checktoken (mit ft_isvalidnbr, ft_hasdup)
- ft_buildstack
- ft_freelist
- ft_assign_index
- ft_issorted         (pruefen ob stack schon sortiert ist)

NOCH ZU MACHEN:
- stack operationen   (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr)
- ft_smallsort        (hardcoded sort fuer <= 5 elemente)
- ft_bigsort          (sort algorithmus fuer grosse stacks)
*/
