/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:13:09 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/03 17:42:35 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *head)
{	
	if (head)
	{
		ft_printf("%i\n", *(int *)(head->content));
		while (head->next != NULL)
		{
			head = head->next;
			ft_printf("%i\n", *(int *)(head->content));
		}
	}
}


void	pointIntPrinter(void *pointer)
{
	printf("%i\n", *((int *)pointer));
}

void	ft_lstprint2(t_list *head)
{

	ft_lstiter(head, pointIntPrinter);
}