/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:13:09 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/11 16:20:05 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *head)
{	
	if (head)
	{
		// ft_printf("%i\n", *(int *)(head->content));
		ft_printf("| %i | ", *(int *)(head->content));
		while (head->next != NULL)
		{
			head = head->next;
			ft_printf("%i | ", *(int *)(head->content));
		}
	}
}


void	pointIntPrinter(void *pointer)
{
	ft_printf("%i\n", *((int *)pointer));
}

void	ft_lstprint2(t_list *head)
{

	ft_lstiter(head, pointIntPrinter);
}