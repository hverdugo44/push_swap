/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:38:53 by hverdugo          #+#    #+#             */
/*   Updated: 2024/11/10 01:51:04 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**matcpy(char **argv, int argc)
{
	int		i;
	char	**str;

	str = (char **)ft_calloc(sizeof(char *), argc);
	if (!str)
		return (0);
	i = 1;
	while (argv[i])
	{
		str[i - 1] = ft_strdup(argv[i]);
		if (str == NULL)
		{
			ft_free(str, i - 1);
			return (NULL);
		}
		i++;
	}
	return (str);
}

void	ft_free(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
	str = NULL;
}
