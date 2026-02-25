/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:17:56 by dsisli            #+#    #+#             */
/*   Updated: 2026/02/26 00:12:48 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <limits.h>

typedef struct node
{
	int			index;
	int			value;
	struct node	*next;
}				t_node;

typedef struct s_move
{
	int	pos_b;
	int	pos_a;
	int	size_b;
	int	size_a;
}				t_move;

void			push(t_node **src, t_node **dst);
void			swap(t_node *stack);
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
t_node			*ft_buildstack(char **tokens);
t_node			*ft_init_stack(int argc, char **argv);
int				ft_checktoken(char **tokens);
int				ft_issorted(t_node *a);
void			ft_assign_index(t_node *a);
void			ft_freelist(t_node *head);
void			ft_freetokens(char **tokens);
void			ft_error(void);
void			ft_smallsort(t_node **a, t_node **b);
void			ft_bigsort(t_node **a, t_node **b);
int				ft_get_max_pos(t_node *stack);
int				ft_get_chunk_size(int size);
void			ft_rotate_b_to_top(t_node **b, int pos, int size);
int				ft_stacksize(t_node *stack);
int				ft_imax(int a, int b);
int				ft_imin(int a, int b);
int				ft_calc_cost(t_move mv);
void			ft_best_pair(t_node **a, t_node **b, t_move *mv);
void			ft_execute(t_node **a, t_node **b, t_move mv);

#endif
