/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:35:12 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/15 16:40:09 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	matoi(const char *s)
{
	int		i;
	int		sig;
	long	res;

	i = 0;
	sig = 1;
	res = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sig = sig * -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		res = (s[i] - 48) + (res * 10);
		i++;
	}
	return (res * sig);
}
