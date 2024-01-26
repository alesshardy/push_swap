/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:06:20 by apintus           #+#    #+#             */
/*   Updated: 2024/01/26 18:20:17 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	swap(t_stack_node **stack)
{
	int	data;

	if (!*stack || !(*stack)->next)
		return;
	data = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = data;
}*/

void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->previous->previous = *head;
	(*head)->previous->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->previous = (*head)->previous;
	(*head)->next = (*head)->previous;
	(*head)->previous = NULL;
}

void	sa(t_stack_node **a)
{
	swap(a);
	printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	printf("sb\n");
}

void	ss(t_stack_node **a,t_stack_node **b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}
