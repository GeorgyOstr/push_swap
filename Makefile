# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/05 23:13:14 by gostroum          #+#    #+#              #
#    Updated: 2025/10/17 00:20:25 by gostroum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH_SWAP = push_swap

PUSH_SWAP_SRCS = main.c utils.c algo.c commands_ps.c commands_r.c commands_rr.c small_algo.c

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP

PUSH_SWAP_DEPS = $(PUSH_SWAP_OBJS:.o=.d)

all: $(NAME_PUSH_SWAP)

$(NAME_PUSH_SWAP): $(PUSH_SWAP_OBJS)
	$(CC) $(PUSH_SWAP_OBJS) -o $(NAME_PUSH_SWAP)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(PUSH_SWAP_OBJS) $(PUSH_SWAP_OBJS) $(PUSH_SWAP_DEPS) $(PUSH_SWAP_DEPS)

fclean: clean
	$(RM) $(NAME_PUSH_SWAP)

re: fclean all

-include $(PUSH_SWAP_DEPS)

.PHONY: all clean fclean re
