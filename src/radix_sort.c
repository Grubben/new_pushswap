/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:02:50 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/04 18:32:46 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ar_min(int *array, size_t arlen)
{
    size_t  i;
    int     min;

    min = array[0];
    i = 1;
    while (i < arlen)
    {
        if (array[i] < min)
            min = array[i];
        i++;
    }
}


static int  *selection_sort(int *array, size_t arlen)
{
    int i;

    i = 0;
    while (i < arlen)
    {
        
    }
}

static int  *convert_toArr(t_list *stack)
{
    int     *array;
    size_t  i, len;

    len = ft_lstlen(stack);
    array = ft_calloc(len, sizeof(int));
    if (!array)
        return (0);
    i = 0;
    while (i < len)
    {
        array[i] = ft_pslstget_it(stack, i);
        i++;
    }
    return (array);
}

static void    indexify(t_list *stack)
{
    int *indexes;

    indexes = convert_toArr(stack);
    indexes = selection_sort(indexes, ft_lstlen(stack));


}

size_t  radix_sort(t_list **a, t_list **b)
{
    size_t  moves;

    moves = 0;
    // indexify()
}