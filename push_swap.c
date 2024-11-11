/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:59:29 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/11 13:16:18 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*str;
	int		length;

	length = 0;
	stack_a = NULL;
	stack_b = NULL;
	str = arg_eval(argv, argc, &length);
	if (!str)
		return (0);
	else if (length == 1)
	{
		free(str);
		return (0);
	}
	stack_bucle(&stack_a, str);
	expected_pos(&stack_a);
	stack_b = stack_a;
	while (stack_b)
	{
		printf("%d\n", stack_b->target);
		stack_b = stack_b->next;
	}
	free_stack(&stack_a);
	return (0);
}
