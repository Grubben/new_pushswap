/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:25:25 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/18 16:33:59 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The first element becomes the last one
int	r(t_list **stack)
{
	t_list	*newtail;
	t_list	*newhead;

	if (stack && *stack)
	{
		newtail = *stack;
		newhead = (*stack)-> next;
		newtail -> next = NULL;
		ft_lstadd_back(&newhead, newtail);
		*stack = newhead;
		return (1);
	}
	return (0);
}

/*
 * Normal rotates the stack
 * the amount specified
 */
int	rotate(t_list **stack, int howmany)
{
	int	q;

	q = howmany;
	while (q > 0)
	{
		r(stack);
		q--;
	}
	return (howmany);
}

// The last element becomes the first one
int	rr(t_list **stack)
{
	t_list	*newhead;
	t_list	*newtail;

	if (stack)
	{
		newhead = ft_lstlast(*stack);
		newtail = ft_lstget_item(*stack, -2);
		newtail -> next = NULL;
		newhead -> next = *stack;
		*stack = newhead;
		return (1);
	}
	return (0);
}

/*
 * Reverse rotates the stack
 * the amount specified
 */
int	revrotate(t_list **stack, int howmany)
{
	int	q;

	q = howmany;
	while (q > 0)
	{
		rr(stack);
		q--;
	}
	return (howmany);
}
