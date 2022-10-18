/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:28:37 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/18 16:52:46 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*args_tolist(char *charray[])
{
	int		i;
	int		*tmp;
	t_list	*lst;

	i = 1;
	lst = NULL;
	while (charray[i])
	{
		tmp = ft_calloc(1, sizeof(int));
		if (!tmp)
			return (NULL);
		*tmp = ft_atoi(charray[i]);
		ft_lstadd_back(&lst, ft_lstnew(tmp));
		i++;
	}
	return (lst);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (write(1, "Not enough arguments\n", 22) && 0);
	if (args_goodp(argv) == 0)
		quit();
	a = args_tolist(argv);
	if (!a)
		return (0);
	if (has_duplicatesp(a))
		quit();
	b = NULL;
	if (argc == 3)
		sort2(&a, 'a');
	if (argc == 4)
		sort3(&a, 'a');
	else if (argc == 5)
		sort4(&a, &b);
	else if (argc == 6)
		sort5(&a, &b);
	else
		sortbig(&a, &b);
	ft_lstclear(&a, free);
	return (0);
}
