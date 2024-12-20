/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:32:28 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/15 13:07:20 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!(*src))
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	if (size_list(*stack_b) == 1)
	{
		push(stack_b, stack_a);
		(*stack_b) = NULL;
	}
	else
		push(stack_b, stack_a);
	write(1, "pa\n", 3);
}
