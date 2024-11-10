/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:22:02 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/10 01:55:10 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;
int		arg_ver(char **argv);
int		*eval_rep(char **str, int length);
int		*arg_eval(char **argv, int argc, int *length);
int		*rep(int *integers, int length);
void	free_stack(t_stack **stack);
void	stack_bucle(t_stack **stack, int *value);
void	stack_fill(t_stack **stack, t_stack *snew);
void	ft_free(char **str, int j);
t_stack	*end(t_stack *stack);
t_stack	*stack_new(int value);
char	**matcpy(char **argv, int argc);
#endif
