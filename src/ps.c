/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:28:37 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/11 16:13:44 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *args_toList(char *charray[])
{
    int     i;
    int     *tmp;
    t_list  *lst;

    i = 1;
    lst = NULL;
    while (charray[i])
    {
        tmp = ft_calloc(1, sizeof(int));
        *tmp = ft_atoi(charray[i]);
        ft_lstadd_back(&lst, ft_lstnew(tmp));

        i++;
    }
    return (lst);
}

int main(int argc, char *argv[])
{
    t_list  *a, *b;
    size_t  moves;

    if (argc < 2)
    {
        write(1, "Not enough arguments\n", 22);
        return (0);
    }
    a = args_toList(argv);
    b = NULL;

    if (argc == 4)
        moves = sort3(&a, 'a');
    else if (argc == 5)
        moves = sort4(&a, &b);
    else if (argc == 6)
        moves = sort5(&a, &b);
    else
        moves = sortbig(&a, &b);
    ft_lstprint(a);
    ft_lstprint(b);

    ft_lstclear(&a, free);
    ft_printf("Number of Moves: %d", moves);
    return (0);
}