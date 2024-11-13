# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 17:36:42 by hverdugo          #+#    #+#              #
#    Updated: 2024/11/13 00:17:20 by hverdugo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FILES = push_swap.c evaluating.c eval_stack.c utils.c algorithm.c push.c rotate.c rrotate.c set_cost.c stack.c swap.c

INCLUDE = push_swap.h

FLAGS = -Wall -Wextra -Werror -g

CC = cc

OFILES = $(FILES:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OFILES) $(INCLUDE) Makefile
	$(CC) $(FLAGS) $(OFILES) libft.a -o $(NAME)

LIBFT: 
	make bonus -C libft
	cp libft/libft.a .

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(OFILES)

fclean:
	make fclean -C libft
	rm -rf $(NAME) $(OFILES)

re:
	make fclean
	make all

.PHONY: all, clean, fclean, re
