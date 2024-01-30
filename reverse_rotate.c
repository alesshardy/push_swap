/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:46:17 by apintus           #+#    #+#             */
/*   Updated: 2024/01/19 15:17:16 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return;
	last_node = find_last(*stack);
	last_node->previous->next = NULL;
	last_node->next = (*stack);
	last_node->previous = NULL;
	(*stack) = last_node;
	last_node->next->previous = last_node;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}
