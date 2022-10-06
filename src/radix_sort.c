/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amc <amc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:02:50 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/07 00:03:51 by amc              ###   ########.fr       */
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


int  *selection_sort(int *array, size_t arlen)
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
    return (array);
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


int *indexify(t_list *stack)
{
    int *indexes;

    indexes = convert_toArr(stack);
    indexes = selection_sort(indexes, ft_lstlen(stack));
    return (indexes);
}


size_t  radix_sort(int *array, t_list **a, t_list **b)
{
    size_t  moves;

    moves = 0;

}

size_t  sortbig(t_list **a, t_list **b)
{
    int *indexes;

    indexes = indexify(*a);
    return (radix_sort(indexes, a, b));
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