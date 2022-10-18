/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:16:21 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/18 16:51:01 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	sort2(t_list **stack, char verbChar)
{
	if (is_ascendingp(*stack))
		return (0);
	r_p(stack, verbChar);
	return (1);
}

size_t	sort3(t_list **stack, char verbChar)
{
	if (is_ascendingp(*stack))
		return (0);
	if (ft_lstmin(*stack) == ft_pslstget_it(*stack, 0))
	{
		rr_p(stack, verbChar);
		return (1 + sort3(stack, verbChar));
	}
	if (ft_lstmax(*stack) == ft_pslstget_it(*stack, 0))
	{
		if (ft_lstmin(*stack) == ft_pslstget_it(*stack, 1))
			return (r_p(stack, verbChar));
		s_p(stack, verbChar);
		return (1 + sort3(stack, verbChar));
	}
	if (ft_lstmin(*stack) == ft_pslstget_it(*stack, 1))
	{
		return (s_p(stack, verbChar));
	}
	return (rr_p(stack, verbChar));
}

size_t	sort4(t_list **a, t_list **b)
{
	size_t	moves;

	moves = 0;
	if (is_ascendingp(*a))
		return (0);
	while (ft_lstmin(*a) != ft_pslstget_it(*a, 0))
		moves += rr_p(a, 'a');
	moves += p_p(b, a, 'b');
	moves += sort3(a, 'a');
	moves += p_p(a, b, 'a');
	return (moves);
}

size_t	sort5(t_list **a, t_list **b)
{
	size_t	moves;

	if (is_ascendingp(*a))
		return (0);
	moves = 0;
	while (ft_lstmin(*a) != ft_pslstget_it(*a, 0))
		moves += rr_p(a, 'a');
	moves += p_p(b, a, 'b');
	moves += sort4(a, b);
	moves += p_p(a, b, 'a');
	return (moves);
}
