/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:02:50 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/11 10:49:36 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ar_minindex(int *array, size_t arlen)
{
    size_t  i;
    int     minindex;

    if (arlen == 0)
        return (-1);
    if (arlen == 1)
        return (0);
    minindex = 0;
    i = 1;
    while (i < arlen)
    {
        if (array[i] < array[minindex])
            minindex = array[i];
        i++;
    }
    return (minindex);
}


void    selection_sort(int *array, size_t arlen)
{
    size_t  i;
    int     tmpint, tmpj;

    i = 0;
    // TODO: Inefficient going through all the array. Only half necessary
    while (i < arlen)
    {
        tmpj = ar_minindex(array + i, arlen - i);
        if (tmpj <= 0)
        {
            i++;
            continue;
        }
        tmpint  = array[i];
        array[i] = array[tmpj];
        array[tmpj] = tmpint;
    }
    // return (array);
}


int  *convert_toArr(t_list *stack)
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


void    indexify(t_list *stack)
{
    int     *indexes;
    int     i;
    t_list  *tmp;
    size_t  index;

    indexes = convert_toArr(stack);
    selection_sort(indexes, ft_lstlen(stack));
    i = 0;
    while (i < ft_lstlen(stack))
    {
        index = ft_lstindex(a, indexes[i]);
        tmp = ft_lstget_item(stack, index);
        tmp->content = i;
        i++;
    }
    free(indexes);
    // return (indexes);
}


size_t  radix_sort(t_list **a, t_list **b)
{
    size_t          moves, lstlen, i;
    unsigned int    shifts;

    moves = 0;
    lstlen = ft_lstlen(*a);
    shifts = 0;
    while (shifts < 8)
    {
        i = 0;
        while (i < lstlen)
        {
            if ((ft_pslstget_it(*a, i)>>shifts) & 1 == 0)
                p_p(b, a, 'b'); // push to b
            else
                r_p(a, 'a');
            i++;
        }
        while (*b)
            p_p(a, b, 'a'); // push back to a
        shifts++;
    }
    return (moves);
}

size_t  sortbig(t_list **a, t_list **b)
{
    int     *indexes;
    size_t  moves;

    indexify(*a);
    moves = radix_sort(a, b);
}

#include <stdio.h>
int main(void)
{
    int arr[] = {1, 3, 2};
    int *ptarr;

    ptarr = selection_sort(arr, 3);

    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[2]);

    return (0);
}