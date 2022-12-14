/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:02:50 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/18 16:47:29 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ar_minindex(int *array, size_t arlen)
{
	size_t	i;
	int		minindex;

	if (arlen == 0)
		return (-1);
	if (arlen == 1)
		return (0);
	minindex = 0;
	i = 1;
	while (i < arlen)
	{
		if (array[i] < array[minindex])
			minindex = i;
		i++;
	}
	return (minindex);
}

static void	selection_sort(int *array, size_t arlen)
{
	size_t	i;
	int		tmpint;
	int		tmpj;

	i = 0;
	while (i < arlen)
	{
		tmpj = i + ar_minindex(array + i, arlen - i);
		if (tmpj <= 0)
		{
			i++;
			continue ;
		}
		tmpint = array[i];
		array[i] = array[tmpj];
		array[tmpj] = tmpint;
		i++;
	}
}

static int	*convert_toarr(t_list *stack)
{
	int		*array;
	size_t	i;
	size_t	len;

	len = ft_lstlen(stack);
	array = ft_calloc(len, sizeof(int));
	if (!array)
		quit();
	i = 0;
	while (i < len)
	{
		array[i] = ft_pslstget_it(stack, i);
		i++;
	}
	return (array);
}

size_t	radix_sort(t_list **a, t_list **b)
{
	size_t			moves;
	size_t			lstlen;
	size_t			i;
	unsigned int	shifts;
	int				lstcont;

	moves = 0;
	lstlen = ft_lstlen(*a);
	shifts = 0;
	while (!is_ascendingp(*a) && shifts < 32)
	{
		i = 0;
		while (i++ < lstlen)
		{
			lstcont = ft_pslstget_it(*a, 0);
			if ((lstcont >> shifts & 1) == 0)
				moves += p_p(b, a, 'b');
			else
				moves += r_p(a, 'a');
		}
		while (*b)
			moves += p_p(a, b, 'a');
		shifts++;
	}
	return (moves);
}

size_t	sortbig(t_list **a, t_list **b)
{
	int		*indexes;
	t_list	*tmp;
	t_list	*old;
	size_t	i;

	if (ft_lstmin(*a) < 0)
	{
		old = ft_lstcpy(*a);
		if (!old)
			quit();
		indexes = convert_toarr(*a);
		selection_sort(indexes, ft_lstlen(*a));
		i = 0;
		while (i < ft_lstlen(old))
		{
			tmp = ft_lstget_item(*a, ft_lstindex(old, indexes[i]));
			tmp -> content = malloc(1 * sizeof(int));
			if (!tmp->content)
				quit();
			*(int *)(tmp->content) = i++;
		}	
		free(indexes);
		ft_lstclear(&old, free);
	}
	return (radix_sort(a, b));
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
