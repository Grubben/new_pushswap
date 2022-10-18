/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:20:35 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/18 16:48:00 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ascendingp(t_list *stack)
{
	int		before;

	if (!stack)
		return (-1);
	before = *(int *)(stack->content);
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (before > *(int *)(stack->content))
			return (0);
		before = *(int *)(stack->content);
	}
	return (1);
}

int	is_descendingp(t_list *stack)
{
	int		before;

	if (!stack)
		return (-1);
	before = *(int *)(stack->content);
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (before < *(int *)(stack->content))
			return (0);
		before = *(int *)(stack->content);
	}
	return (1);
}

/*
 * [1, 2, 3]
 */
int	set_ascending(t_list **stack, char verbChar)
{
	int	moves;

	moves = 0;
	if (ft_lstindex(*stack, ft_lstmax(*stack)) > (ft_lstlen(*stack) / 2))
	{
		while (*(int *)((*stack)->content) != ft_lstmin(*stack))
		{
			rr_p(stack, verbChar);
			moves++;
		}
	}
	else
	{
		while (*(int *)((*stack)->content) != ft_lstmin(*stack))
		{
			r_p(stack, verbChar);
			moves++;
		}
	}
	return (moves);
}

/*
 * [3, 2, 1]
 */
int	set_descending(t_list **stack, char verbChar)
{
	int	moves;

	if (!stack)
		return (0);
	moves = 0;
	if (ft_lstindex(*stack, ft_lstmax(*stack)) > (ft_lstlen(*stack) / 2))
	{
		while (*(int *)((*stack)->content) != ft_lstmax(*stack))
		{
			rr_p(stack, verbChar);
			moves++;
		}
	}
	else
	{
		while (*(int *)((*stack)->content) != ft_lstmax(*stack))
		{
			r_p(stack, verbChar);
			moves++;
		}
	}
	return (moves);
}

void	nada(void *el)
{
	(void)el;
}

/*
int	main(void)
{
	t_list	*stack1;
	// t_list	*stack2;
	t_list	el;
	// int		counter;
	int		n[4] = {1,3,2,4};

	// counter = 0;
	// stack1 = NULL;

	el.content = (void *)(&n);
	el.next = NULL;

	
	stack1 = &el;

	ft_lstadd_back(&stack1, ft_lstnew((void *)&(n[1])));

	ft_lstadd_back(&stack1, ft_lstnew((void *)&(n[2])));

	ft_lstadd_back(&stack1, ft_lstnew((void *)&(n[3])));

	ft_lstprint(stack1);

	int	is_swted;
	is_swted = switchedP(stack1, is_ascendingp);
	ft_printf("\n%d\n", is_swted);
	// ft_printf("%d\n", *(int *)(stack1->next->next->next->content));

	// Check asc/desc functions
	// ft_printf("%d\n", is_ascendingp(stack1));
	// ft_printf("%d\n", is_descendingp(stack1));
}
*/
