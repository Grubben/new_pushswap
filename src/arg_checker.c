/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amc <amc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:22:55 by amc               #+#    #+#             */
/*   Updated: 2022/10/12 17:06:15 by amc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(void)
{
	write(1, "ERROR\n", 7);
	exit(0);
}

int	is_goodnumP(char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (0);
		i++;
	}
	if (ft_atoi(string) > 2147483647)
		return (0);
	return (1);
}

int	args_goodP(char *argv[])
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		if (is_goodnumP(argv[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}