/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:21:59 by amaria-d          #+#    #+#             */
/*   Updated: 2022/10/18 16:52:46 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

size_t	sort2(t_list **stack, char verbChar);

size_t	sort3(t_list **stack, char verbChar);

size_t	sort4(t_list **a, t_list **b);

size_t	sort5(t_list **a, t_list **b);

size_t	sortbig(t_list **a, t_list **b);

/*  OPS */

/*
 * Swap the first 2 elements at the top of stack
 */
int		s(t_list **stack);

/*
 * Take the first element at the top of stack2 and put it at the top of stack1
 */
int		p(t_list **stack1, t_list **stack2);

/*
 * The first element becomes the last one
 */
int		r(t_list **stack);

/*
 * The last element becomes the first one
 */
int		rr(t_list **stack);

/*
 * Normal rotates the stack
 * the amount specified
 */
int		rotate(t_list **stack, int howMany);

/*
 * Reverse rotates the stack
 * the amount specified
 */
int		revrotate(t_list **stack, int howMany);

/*	PRINTER OPS	*/

int		s_p(t_list **stack, char verbChar);

int		p_p(t_list **stack1, t_list **stack2, char verbChar);

int		r_p(t_list **stack, char verbChar);

int		rr_p(t_list **stack, char verbChar);

int		rotate_p(t_list **stack, int howMany, char verbChar);

int		revrotate_p(t_list **stack, int howMany, char verbChar);

/*	STACKOPS	*/

int		is_ascendingp(t_list *stack);

int		is_descendingp(t_list *stack);

/*	ARG_CHECKER	*/
int		args_goodp(char *argv[]);

void	quit(void);

int		has_duplicatesp(t_list *stack);

#endif
