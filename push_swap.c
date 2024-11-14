/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:59:29 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/14 01:12:20 by hverdugo         ###   ########.fr       */
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
	stack_bucle(&stack_a, str, length);
	expected_pos(&stack_a);
	fill_stackb(&stack_a, &stack_b);
	set_cost(&stack_a, &stack_b);
	find_target(&stack_a, &stack_b, length);
	temp = stack_b;
	printf("	Ca		Cb		\n");
	while (temp)
	{
		printf("	%d		%d\n", temp->cost_a, temp->cost_b);
		temp = temp->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
