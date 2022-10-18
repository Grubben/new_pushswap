/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:22:55 by amc               #+#    #+#             */
/*   Updated: 2022/10/18 16:53:16 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(void)
{
	write(1, "ERROR\n", 7);
	exit(0);
}

int	is_goodnump(char *string)
{
	size_t	i;

	i = 0;
	if (string[i] == '-')
		i = 1;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (0);
		i++;
	}
	if ((ft_atol(string) > 2147483647) || ft_atol(string) < -2147483648)
		return (0);
	return (1);
}

int	args_goodp(char *argv[])
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		if (is_goodnump(argv[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicatesp(t_list *stack)
{
	size_t	len;
	size_t	j;
	size_t	i;

	len = ft_lstlen(stack);
	j = 0;
	while (j < len)
	{
		i = j + 1;
		while (i < len)
		{			
			if (ft_pslstget_it(stack, j) == ft_pslstget_it(stack, i))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
