# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 17:36:42 by hverdugo          #+#    #+#              #
#    Updated: 2024/11/15 16:45:04 by hverdugo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a

FILES = push_swap.c evaluating.c eval_stack.c utils.c algorithm.c push.c rotate.c rrotate.c set_cost.c stack.c swap.c find_target.c choose_move.c matoi.c

INCLUDE = push_swap.h

FLAGS = -Wall -Wextra -Werror -g

CC = cc

OFILES = $(FILES:.c=.o)

all: libft_compile $(NAME)

libft_compile:
	make bonus -C libft
	cp libft/libft.a .

$(NAME): $(OFILES) $(INCLUDE) Makefile libft.a
	$(CC) $(FLAGS) $(OFILES) libft.a -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(OFILES)

fclean:
	make fclean -C libft
	rm -rf $(NAME) $(OFILES) libft.a

re:
	make fclean
	make all

.PHONY: all, clean, fclean, re
