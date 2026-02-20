/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:17:56 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/20 16:40:49 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include	<stdio.h>
#include	"libft.h"
#include	<limits.h>


typedef struct	node
{
	int	index;
	int	value;
	struct node	*prev;
	struct node	*next;
}t_node;

typedef	struct stack
{
	int	size;
	t_node token;
}t_stack;


void	sa(); //swap a
void	sb(); //swap b
void	ss(); //sa and sb same time
void	pa(); //push a
void	pb(); //push b
void	ra(); //rotate a
void	rb(); //rotate b
void	rr(); //rotate a and b
void	rra(); //reverse ra
void	rrb(); //reverse rb
void	rrr(); //rra und rrb same time
int	ft_checktoken(char **tokens);
static int	ft_hasdup(char **tokens);
static int	ft_isvalidnbr(char *str);
void	ft_assign_index(t_node a);
void	ft_freelist(t_node *head);
void	ft_freetokens(char** tokens);

#endif
