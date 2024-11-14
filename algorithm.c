/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:00:09 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/13 13:11:28 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_stack(t_stack **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		if ((*stack)->num > (*stack)->next->next->num)
			rotate_a(stack);
	if ((*stack)->next->num > (*stack)->num)
		if ((*stack)->next->num > (*stack)->next->next->num)
			rrotate_a(stack);
	if ((*stack)->num > (*stack)->next->num)
		swap_a(stack);
}

void	fill_stackb(t_stack **stack_a, t_stack **stack_b)
{
	while (size_list(*stack_a) > 3)
		push_b(stack_a, stack_b);
	three_stack(stack_a);
}

void	fill_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		i;
	int		j;

	temp = *stack_a;
	i = 1;
	j = 1;
	while (temp)
	{
		temp->pos = i;
		i++;
		temp = temp->next;
	}
	temp = *stack_b;
	while (temp)
	{
		temp->pos = j;
		j++;
		temp = temp->next;
	}
}
/*
void	find_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_b)
	{
		while (temp_a)
		{
*/
