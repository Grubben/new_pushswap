/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amc <amc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:26:43 by amc               #+#    #+#             */
/*   Updated: 2022/09/23 19:10:26 by amc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Presumes t_list:content is originally int type
*/
int	ft_lstmin(t_list *lst)
{
	int	min;

	if (!lst)
	{
		ft_printf("ERROR\n");
		// exit(-1);
	}
	min = *(int *)(lst->content);
	while (lst->next != NULL)
	{
		lst = lst -> next;
		if (*(int *)(lst->content) < min)
			min = *(int *)(lst->content);
	}
	return (min);

}