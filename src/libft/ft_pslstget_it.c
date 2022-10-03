/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pslstget_it.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amc <amc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:03:24 by amc               #+#    #+#             */
/*   Updated: 2022/09/26 23:06:33 by amc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_lstget_item but presumes
 * t_list::content is an (int *)
 */
int	ft_pslstget_it(t_list *lst, ssize_t index)
{
	return (
		*(int *)(ft_lstget_item(lst, index)->content)
	);
}