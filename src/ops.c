/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:25:22 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/18 16:30:55 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack
int	s(t_list **stack)
{
	t_list	*oldfirst;
	t_list	*newfirst;

	if (stack && ft_lstsize(*stack) > 1)
	{
		oldfirst = *stack;
		newfirst = (*stack)-> next;
		oldfirst -> next = newfirst -> next;
		newfirst -> next = oldfirst;
		*stack = newfirst;
		return (1);
	}
	return (0);
}

// Take the first element at the top of stack2 and put it at the top of stack1
int	p(t_list **stack1, t_list **stack2)
{
	t_list	*olds1;
	t_list	*olds2;

	if (stack2 && ft_lstlen(*stack2) >= 1)
	{
		olds1 = *stack1;
		olds2 = *stack2;
		*stack2 = (*stack2)->next;
		*stack1 = olds2;
		olds2->next = olds1;
		return (1);
	}
	return (0);
}

int	s_p(t_list **stack, char verbChar)
{
	ft_printf("s%c\n", verbChar);
	return (s(stack));
}

// Take the first element at the top of stack2 and put it at the top of stack1
int	p_p(t_list **stack1, t_list **stack2, char verbChar)
{
	ft_printf("p%c\n", verbChar);
	return (p(stack1, stack2));
}

/*
int	main(void)
{
	t_list	*stack1;
	t_list	*stack2;
	t_list	el;
	int		counter;

	counter = 0;
	stack1 = NULL;

	el.content = (void *)"good";
	el.next = NULL;

	ft_printf("%d\n", ft_lstsize(stack1)); // == 0

	stack1 = ft_lstnew((void *)"hello");
	ft_printf("%d\n", ft_lstsize(stack1)); // == 1

	ft_lstadd_front(&stack1, &el);
	ft_printf("%d\n", ft_lstsize(stack1)); // == 2

	ft_lstadd_back(&stack1, ft_lstnew((void *)"bye"));
	ft_printf("%d\n", ft_lstsize(stack1)); // == 3

	ft_lstadd_back(&stack1, ft_lstnew((void *)"greetings"));
	ft_printf("%d\n", ft_lstsize(stack1)); // == 4

	ft_lstprint(stack1);

	stack2 = ft_lstnew((void *)"Morning");
	ft_lstadd_back(&stack2, ft_lstnew((void *)"Madam"));
	ft_printf("%d\n", ft_lstsize(stack2)); // == 1

	ft_lstprint(stack2);

	// ft_printf("\nChecking S function\n");
	// // Check if s func works
	// printf("%d\n", s(&stack1));
	// ft_lstprint(stack1);
	// s(&stack1);

	// ft_printf("\nChecking P function\n");
	// // Check if p func works
	// counter += p(&stack1, &stack2);
	// ft_lstprint(stack1);
	// ft_printf("\n");
	// ft_lstprint(stack2);

	// // ft_printf("\n");
	// ft_printf("\n");
	// counter += p(&stack2, &stack1);
	// counter += p(&stack2, &stack1);
	// counter += p(&stack2, &stack1);
	// counter += p(&stack2, &stack1);
	// counter += p(&stack2, &stack1);
	// counter += p(&stack2, &stack1);
	// ft_lstprint(stack1);
	// printf("%d\n", ft_lstsize(stack1)); // == 0
	// printf("%d\n", ft_lstsize(stack2)); // == 5

	// ft_printf("\n");
	// ft_lstprint(stack2);


	// ft_printf("\nChecking R function\n");
	// // Check the r func
	// ft_lstprint(stack1);
	// counter += r(&stack1);
	// counter += r(&	stack1);
	// ft_printf("\n");
	// ft_lstprint(stack1);


	ft_printf("\nChecking RR function\n");
	// Check the rr func
	ft_lstprint(stack1);
	counter += rr(&stack1);
	// counter += rr(&	stack1);
	ft_printf("\n");
	ft_lstprint(stack1);


	ft_printf("%d\n", counter);
}
*/