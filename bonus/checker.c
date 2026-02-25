/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:18:23 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/25 23:42:02 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	char	*line;

	if (argc < 2)
		return (0);
	b = NULL;
	a = ft_init_stack(argc, argv);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		line[ft_strlen(line) - 1] = '\0';
		ft_execute_instruction(&a, &b, line);
		free(line);
	}
	if (ft_issorted(a) && !b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_freelist(a);
	ft_freelist(b);
	return (0);
}
