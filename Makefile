# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 17:00:00 by dsisli            #+#    #+#              #
#    Updated: 2026/02/26 00:15:09 by dsisli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= include/Libft
LIBFT		= $(LIBFT_DIR)/libft.a

OBJ_DIR = obj
PRINTF_DIR	= include/ft_printf
PRINTF		= $(PRINTF_DIR)/ft_printf.a

INCLUDES	= -I include -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I bonus -I $(GNL_DIR)

SRCS		=	srcs/push_swap.c				\
				srcs/ft_pushswap_utils.c		\
				srcs/stack/ft_buildstack.c		\
				srcs/stack/ft_assign_index.c	\
				srcs/ops/ops_push.c				\
				srcs/ops/ops_swap.c				\
				srcs/ops/ops_rotate.c			\
				srcs/ops/ops_reverse_rotate.c	\
				srcs/sort/ft_issorted.c			\
				srcs/sort/small_sort.c			\
				srcs/sort/big_sort.c			\
				srcs/sort/ft_bigsort_utils.c	\
				srcs/sort/ft_target.c			\
				srcs/sort/ft_execute.c

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

BONUS_NAME	= checker
GNL_DIR		= include/gnl

BONUS_SRCS	=	bonus/checker.c			\
                bonus/checker_utils.c		\
                bonus/checker_ops1.c		\
                bonus/checker_ops2.c		\
                bonus/checker_ops3.c		\
                $(GNL_DIR)/get_next_line.c	\
                $(GNL_DIR)/get_next_line_utils.c	\
                srcs/ft_pushswap_utils.c	\
                srcs/stack/ft_buildstack.c	\
                srcs/stack/ft_assign_index.c	\
                srcs/ops/ops_push.c				\
                srcs/ops/ops_swap.c				\
                srcs/ops/ops_rotate.c			\
                srcs/ops/ops_reverse_rotate.c	\
                srcs/sort/ft_issorted.c			\
                srcs/sort/ft_bigsort_utils.c	\
                srcs/sort/ft_target.c			\
                srcs/sort/ft_execute.c

BONUS_OBJS	= $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -l:ft_printf.a -o $(NAME)

bonus:  $(LIBFT) $(PRINTF) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -l:ft_printf.a -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
