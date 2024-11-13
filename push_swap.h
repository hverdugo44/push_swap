/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:00:09 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/12 22:50:24 by hverdugo         ###   ########.fr       */
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
int		size_list(t_stack *stack);
int		*eval_rep(char **str, int length);
int		*arg_eval(char **argv, int argc, long int *length);
int		*rep(int *integers, int length);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
void	stack_bucle(t_stack **stack, int *value);
void	stack_fill(t_stack **stack, t_stack *snew);
void	ft_free(char **str, long int j);
void	swap(t_stack **stack);
void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b);
void	rrotate(t_stack **stack);
void	rrotate_a(t_stack **stack);
void	rrotate_b(t_stack **stack);
void	rrotate_rrr(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **src, t_stack **dest);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	three_stack(t_stack **stack);
void	expected_pos(t_stack **stack);
void	set_cost(t_stack **stack_a, t_stack **stack_b);
void	fill_stackb(t_stack **stack_a, t_stack **stack_b);
void	fill_pos(t_stack **stack_a, t_stack **stack_b);
t_stack	*end(t_stack *stack);
t_stack	*penultimate(t_stack *stack);
t_stack	*stack_new(int value);
char	**matcpy(char **argv, int argc);
#endif
