/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:25:26 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/03 15:25:27 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int s_p(t_list **stack, char verbChar)
{
    ft_printf("s%c\n", verbChar);
    return (s(stack));
}

int p_p(t_list **stack1, t_list **stack2, char verbChar)
{
    ft_printf("p%c\n", verbChar);
    return (p(stack1, stack2));
}

int r_p(t_list **stack, char verbChar)
{
    ft_printf("r%c\n", verbChar);
    return (r(stack));
}

int rr_p(t_list **stack, char verbChar)
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

int	revRotate_p(t_list **stack, int howMany, char verbChar)
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