/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:17:56 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/23 17:00:37 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct node
{
	int			index;
	int			value;
	struct node	*prev;
	struct node	*next;
}				t_node;

typedef struct stack
{
	int			size;
	t_node		token;
}				t_stack;

void			push(t_node **src, t_node **dst);
void			swap(t_node *stack);
void			rotate(t_node **stack);
void			reverse_rotate(t_node **stack);
void			sa(t_node *stack);
void			sb(t_node *stack);
void			ss(t_node *a, t_node *b);
void			pa(t_node **a, t_node **b);
void			pb(t_node **a, t_node **b);
void			ra(t_node **stack);
void			rb(t_node **stack);
void			rr(t_node **stack_a, t_node **stack_b);
void			rra(t_node **stack);
void			rrb(t_node **stack);
void			rrr(t_node **stack_a, t_node **stack_b);
int				ft_checktoken(char **tokens);
static int		ft_hasdup(char **tokens);
static int		ft_isvalidnbr(char *str);
void			ft_assign_index(t_node a);
void			ft_freelist(t_node *head);
void			ft_freetokens(char **tokens);

#endif
