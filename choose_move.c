/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:08:14 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/15 13:08:40 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	same_move(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (temp->cost_a > 0 && temp->cost_b > 0)
	{
		if (temp->cost_a > temp->cost_b)
			temp->target = temp->cost_a;
		else
			temp->target = temp->cost_b;
	}
	else
	{
		if (temp->cost_a > temp->cost_b)
			temp->target = temp->cost_b * -1;
		else
			temp->target = temp->cost_a * -1;
	}
}

static void	find_cheepest(t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_b;
	while (temp)
	{
		if ((temp->cost_a > 0 && temp->cost_b > 0)
			|| (temp->cost_a < 0 && temp->cost_b < 0))
			same_move(&temp);
		else
		{
			if (temp->cost_a - temp->cost_b >= 0)
				temp->target = temp->cost_a - temp->cost_b;
			else
				temp->target = (temp->cost_a - temp->cost_b) * -1;
		}
		temp = temp->next;
	}
}

static void	select_moves(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	if (temp->cost_a > 0 && temp->cost_b > 0)
		rotate_rr(stack_a, stack_b);
	else if (temp->cost_a < 0 && temp->cost_b < 0)
		rrotate_rrr(stack_a, stack_b);
	else if (temp->cost_a == 0)
	{
		if (temp->cost_b < 0)
			rrotate_b(stack_b);
		else
			rotate_b(stack_b);
	}
	else
	{
		if (temp->cost_a < 0)
			rrotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
}

static void	do_moves(t_stack **stack_a, t_stack **stack_b, int length)
{
	t_stack	*temp;
	int		i;

	i = 1;
	while (i < length)
	{
		temp = *stack_b;
		while (temp)
		{
			if (temp->target == i)
			{
				select_moves(stack_a, stack_b, temp);
				return ;
			}
			temp = temp->next;
		}
		i++;
	}
}

void	move(t_stack **stack_a, t_stack **stack_b, int length)
{
	expected_pos(stack_a);
	if (is_sorted(*stack_a) == 1)
		fill_stackb(stack_a, stack_b);
	else
		return ;
	while (*stack_b)
	{
		set_cost(stack_a, stack_b);
		find_target(stack_a, stack_b, length);
		find_cheepest(stack_b);
		if ((*stack_b)->target == 0)
			push_a(stack_a, stack_b);
		else
			do_moves(stack_a, stack_b, length);
		if (stack_b == NULL)
			return ;
	}
}
