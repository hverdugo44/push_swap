/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:17:20 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/13 01:45:07 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	costa(t_stack **stack_a)
{
	t_stack	*temp;
	int		i;
	int		j;

	temp = *stack_a;
	j = size_list(*stack_a) / 2;
	i = 0;
	while (i < j + 1)
	{
		temp->cost_a = i;
		temp = temp->next;
		i++;
	}
	if ((size_list(*stack_a) % 2) == 0)
		i--;
	i--;
	while (i > 0)
	{
		temp->cost_a = i * -1;
		temp = temp->next;
		i--;
	}
}

static void	costb(t_stack **stack_b)
{
	t_stack	*temp;
	int		i;
	int		j;

	j = size_list(*stack_b) / 2;
	temp = *stack_b;
	i = 0;
	while (i < j + 1)
	{
		temp->cost_b = i;
		temp = temp->next;
		i++;
	}
	if ((size_list(*stack_b) % 2) == 0)
		i--;
	i--;
	while (i > 0)
	{
		temp->cost_b = i * -1;
		temp = temp->next;
		i--;
	}
}

void	set_cost(t_stack **stack_a, t_stack **stack_b)
{
	costa(stack_a);
	costb(stack_b);
}
