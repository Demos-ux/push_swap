# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 17:00:00 by dsisli            #+#    #+#              #
#    Updated: 2026/02/23 22:07:57 by dsisli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= include/Libft
LIBFT		= $(LIBFT_DIR)/libft.a

PRINTF_DIR	= include/ft_printf
PRINTF		= $(PRINTF_DIR)/ft_printf.a

INCLUDES	= -I include -I $(LIBFT_DIR) -I $(PRINTF_DIR)

SRCS		=	srcs/push_swap.c				\
				srcs/ft_pushswap_utils.c		\
				srcs/stack/ft_buildstack.c		\
				srcs/stack/ft_assign_index.c	\
				srcs/sort/ft_issorted.c			\
				srcs/sort/big_sort.c			\
				srcs/sort/ft_bigsort_utils.c	\
				srcs/sort/small_sort.c			\
				srcs/sort/push/push.c			\
				srcs/sort/push/pa.c				\
				srcs/sort/push/pb.c				\
				srcs/sort/swap/swap.c			\
				srcs/sort/swap/sa.c				\
				srcs/sort/swap/sb.c				\
				srcs/sort/swap/ss.c				\
				srcs/sort/rotate/rotate.c		\
				srcs/sort/rotate/ra.c			\
				srcs/sort/rotate/rb.c			\
				srcs/sort/rotate/rr.c			\
				srcs/sort/rotate/reverse_rotate.c	\
				srcs/sort/rotate/rra.c			\
				srcs/sort/rotate/rrb.c			\
				srcs/sort/rotate/rrr.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -l:ft_printf.a -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
