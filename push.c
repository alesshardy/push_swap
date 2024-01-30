/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:34:38 by apintus           #+#    #+#             */
/*   Updated: 2024/01/30 11:33:57 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*push_node;

	if (!src)
		return ;
	push_node = (*src);
	(*src) = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->previous = push_node;
		*dest = push_node;
	}
}

void	pa(t_stack_node **b, t_stack_node**a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node**b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
