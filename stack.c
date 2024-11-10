/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:43:26 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/10 23:47:51 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = value;
	new->index = 0;
	new->pos = -1;
	new->target = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	stack_fill(t_stack **stack, t_stack *snew)
{
	t_stack	*final;

	final = NULL;
	if (!snew)
		return ;
	if (!*stack)
	{
		*stack = snew;
		return ;
	}
	final = end(*stack);
	final->next = snew;
}

t_stack	*end(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (NULL);
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_bucle(t_stack **stack, int *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		stack_fill(stack, stack_new(value[i]));
		i++;
	}
	free(value);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
