/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:12:06 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/10 23:53:57 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*fin;

	temp = (*stack);
	fin = penultimate(*stack);
	(*stack) = end(*stack);
	(*stack)->next = temp;
	fin->next = NULL;
}

void	rrotate_a(t_stack **stack)
{
	rrotate(stack);
	write(1, "rra\n", 4);
}

void	rrotate_b(t_stack **stack)
{
	rrotate(stack);
	write(1, "rrb\n", 4);
}

void	rrotate_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	write(1, "rrr\n", 4);
}

