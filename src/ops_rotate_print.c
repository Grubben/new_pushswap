/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:25:26 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/18 16:27:01 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_p(t_list **stack, char verbChar)
{
	ft_printf("r%c\n", verbChar);
	return (r(stack));
}

int	rr_p(t_list **stack, char verbChar)
{
	ft_printf("rr%c\n", verbChar);
	return (rr(stack));
}

int	rotate_p(t_list **stack, int howMany, char verbChar)
{
	int	q;

	q = howMany;
	while (q > 0)
	{
		r_p(stack, verbChar);
		q--;
	}
	return (howMany);
}

int	revrotate_p(t_list **stack, int howMany, char verbChar)
{
	int	q;

	q = howMany;
	while (q > 0)
	{
		rr_p(stack, verbChar);
		q--;
	}
	return (howMany);
}
