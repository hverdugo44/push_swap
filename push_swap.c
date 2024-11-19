/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:59:29 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/19 13:54:42 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*str;
	long	length;

	length = 0;
	stack_a = NULL;
	stack_b = NULL;
	str = arg_eval(argv, argc, &length);
	if (argc == 1)
		return (0);
	else if (!str)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else if (length == 1 || argc == 1)
	{
		free(str);
		return (0);
	}
	stack_bucle(&stack_a, str, length);
	algorithm(&stack_a, &stack_b, length);
	free_stack(&stack_a);
	return (0);
}
