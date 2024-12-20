/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:19:33 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/19 13:15:13 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_ver(char **argv)
{
	int	in1;
	int	in2;

	in1 = 0;
	while (argv[in1])
	{
		in2 = 0;
		while (argv[in1][in2])
		{
			if ((argv[in1][in2] < '0' || argv[in1][in2] > '9')
				&& argv[in1][in2] != '-')
				return (1);
			in2++;
		}
		in1++;
	}
	return (0);
}

int	*arg_eval(char **argv, int argc, long int *length)
{
	char	**str;
	int		*res;

	if (argc == 1)
		return (NULL);
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else
		str = matcpy(argv, argc);
	if (!str)
		return (NULL);
	while (str[length[0]])
		length[0]++;
	if (arg_ver(str) == 1 || length[0] > 2147483647)
	{
		ft_free(str, (length[0] - 1));
		return (NULL);
	}
	res = eval_rep(str, length[0]);
	return (res);
}

int	*eval_rep(char **str, int length)
{
	long	x;
	int		i;
	int		*integers;

	i = 0;
	integers = (int *)ft_calloc(sizeof(int), length + 1);
	if (!integers)
		return (NULL);
	while (i < length)
	{
		x = matoi(str[i]);
		if (x < -2147483648 || x > 2147483647)
		{
			free(integers);
			ft_free(str, length - 1);
			return (NULL);
		}
		integers[i] = (int)x;
		i++;
	}
	ft_free(str, length - 1);
	return (rep(integers, length));
}

int	*rep(int *integers, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (integers[i] == integers[j])
			{
				free(integers);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (integers);
}
