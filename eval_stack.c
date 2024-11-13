/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:08:35 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/12 18:36:26 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	expected_pos(t_stack **stack)
{
	int		j;
	t_stack	*temp;
	t_stack	*min;

	j = 0;
	while (j <= size_list(*stack))
	{
		temp = *stack;
		min = NULL;
		while (temp)
		{
			if (temp->index == -1 && (!min || temp->num < min->num))
				min = temp;
			temp = temp->next;
		}
		if (min)
			min->index = j;
		j++;
	}
}
