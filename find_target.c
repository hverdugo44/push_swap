/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:32:18 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/14 01:08:26 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_small(t_stack **stack_a, t_stack **stack_b, int length)
{
	t_stack	*temp;
	int		i;

	i = 0;
	while (i < length)
	{
		temp = *stack_a;
		while (temp)
		{
			if (temp->index - i == 1)
			{
				(*stack_b)->cost_a = temp->cost_a;
				return ;
			}
			temp = temp->next;
		}
		i++;
	}
}

static void	find_big(t_stack **stack_a, t_stack **stack_b, int length)
{
	t_stack	*temp;
	int		i;

	i = 1;
	while (i < length)
	{
		temp = *stack_a;
		while (temp)
		{
			if (temp->index - i == (*stack_b)->index)
			{
				(*stack_b)->cost_a = temp->cost_a;
				return ;
			}
			temp = temp->next;
		}
		i++;
	}
}

static int	select_fun(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (temp->index > (*stack_b)->index)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	find_target(t_stack **stack_a, t_stack **stack_b, int length)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *stack_a;
	temp2 = *stack_b;
	while (temp2)
	{
		if (select_fun(&temp1, &temp2) == 0)
			find_small(&temp1, &temp2, length);
		else
			find_big(&temp1, &temp2, length);
		temp2 = temp2->next;
	}
}
