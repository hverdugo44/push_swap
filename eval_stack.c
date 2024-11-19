/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:08:35 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/15 13:04:08 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		i;
	int		j;

	i = 1;
	j = size_list(stack);
	temp = stack;
	while (temp->index != 1)
		temp = temp->next;
	while (i < j)
	{
		if (temp->next == NULL)
		{
			temp2 = temp;
			temp->next = stack;
		}
		if (temp->index > temp->next->index)
			return (1);
		temp = temp->next;
		i++;
	}
	temp2->next = NULL;
	return (0);
}

void	expected_pos(t_stack **stack)
{
	int		j;
	t_stack	*temp;
	t_stack	*min;

	j = 1;
	while (j <= size_list(*stack))
	{
		temp = *stack;
		min = NULL;
		while (temp)
		{
			if (temp->index == 0 && (!min || temp->num < min->num))
				min = temp;
			temp = temp->next;
		}
		if (min)
			min->index = j;
		j++;
	}
}
