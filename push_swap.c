/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:59:29 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/13 01:27:22 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*temp;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*str;
	long	length;

	length = 0;
	stack_a = NULL;
	stack_b = NULL;
	str = arg_eval(argv, argc, &length);
	if (!str)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else if (length == 1)
	{
		free(str);
		return (0);
	}
	stack_bucle(&stack_a, str);
	expected_pos(&stack_a);
	fill_stackb(&stack_a, &stack_b);
	set_cost(&stack_a, &stack_b);
	temp = stack_a;
	while (temp)
	{
		printf("%d\n", temp->cost_a);
		temp = temp->next;
	}
	printf("\n");
	temp = stack_b;
	while (temp)
	{
		printf("%d\n", temp->cost_b);
		temp = temp->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
