/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:48:07 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/10 23:10:12 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*fin;

	temp = (*stack);
	fin = end(*stack);
	*stack = (*stack)->next;
	temp->next = NULL;
	fin->next = temp;
}

void	rotate_a(t_stack **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
