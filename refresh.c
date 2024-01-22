/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:45:28 by apintus           #+#    #+#             */
/*   Updated: 2024/01/22 16:56:53 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refresh_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if(!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	refresh_target_a(t_stack_node *a, t_stack_node *b)
{
	
}

void	refresh_node_a(t_stack_node *a, t_stack_node *b)
{
	refresh_index(a);
	refresh_index(b);
	refresh_target_a(a);
	cost_a(a, b);
	set_cheapest(a);
}
