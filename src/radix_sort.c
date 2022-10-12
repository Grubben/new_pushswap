/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amc <amc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:02:50 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/12 16:17:54 by amc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int     ar_minindex(int *array, size_t arlen)
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


static void    selection_sort(int *array, size_t arlen)
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
    int     *indexes;
    t_list  *tmp;
    size_t  i, index;

    indexes = convert_toArr(stack);
    selection_sort(indexes, ft_lstlen(stack));
    i = 0;
    while (i < ft_lstlen(stack))
    {
        index = ft_lstindex(stack, indexes[i]);
        tmp = ft_lstget_item(stack, index);
        *(int *)(tmp->content) = i;
        i++;
    }
    free(indexes);
    // return (indexes);
}


size_t  radix_sort(t_list **a, t_list **b)
{
    size_t          moves, lstlen, i;
    unsigned int    shifts;
    int             lstcont;

    moves = 0;
    lstlen = ft_lstlen(*a);
    shifts = 0;
    while (!is_ascendingP(*a) && shifts < 32)
    {
        i = 0;
        while (i < lstlen)
        {
            lstcont = ft_pslstget_it(*a, 0);
            if ((lstcont >> shifts & 1) == 0)
                moves += p_p(b, a, 'b'); // push to b
            else
                moves += r_p(a, 'a');
            i++;
        }
        while (*b)
            moves += p_p(a, b, 'a'); // push back to a
        // ft_lstprint(*a);
        shifts++;
    }
    return (moves);
}

size_t  sortbig(t_list **a, t_list **b)
{
    size_t  moves;

    if (ft_lstmin(*a) < 0)
        indexify(*a);
    moves = radix_sort(a, b);
    return (moves);
}

/*
int main(void)
{
    int *arr;
    
    arr = ft_calloc(3, sizeof(int));
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 2;
    // int *ptarr;

    // ptarr = selection_sort(arr, 3);

    // printf("%d\n", arr[0]);
    // printf("%d\n", arr[1]);
    // printf("%d\n", arr[2]);
    t_list  *head;

    head = NULL;
    ft_lstadd_back(&head, ft_lstnew(arr+0));
    ft_lstadd_back(&head, ft_lstnew(arr+1));
    ft_lstadd_back(&head, ft_lstnew(arr+2));

    ft_lstprint(head);

    
    t_list  *b;
    size_t  moves;
    b = NULL;
    moves = sortbig(&head, &b);

    ft_lstprint(head);
    
    ft_printf("Number of Moves: %d", moves);
    
    return (0);
}
*/
