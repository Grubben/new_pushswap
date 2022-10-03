/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:16:21 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/03 15:46:59 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t  sort3(t_list **a, t_list **b)
{
    if (is_ascendingP(*a))
        return (0);
    if (ft_lstmin(*a) == ft_pslstget_it(*a, 0))
        {
            rr_p(a, 'a');
            return (1 + sort3(a, b));
        }
    if (ft_lstmax(*a) == ft_pslstget_it(*a, 0))
    {
            if (ft_lstmin(*a) == ft_pslstget_it(*a, 1))
                return (r_p(a, 'a'));
            s_p(a, 'a');
            return (1 + sort3(a, b));
    }
    // first is 2
    
    if (ft_lstmin(*a) == ft_pslstget_it(*a, 1))
    {
        return (s_p(a, 'a'));
    }
    return (rr_p(a, 'a'));
}