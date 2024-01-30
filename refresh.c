/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:45:28 by apintus           #+#    #+#             */
/*   Updated: 2024/01/25 17:16:32 by apintus          ###   ########.fr       */
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
	t_stack_node	*current_b;
	t_stack_node	*target;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match) //the closest smaller nbr
			{
				best_match = current_b->nbr;
				//printf("SIUUUUU {%ld} ", best_match);
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		//printf(" NEXT ");
		a = a->next;
	}
}

void	cost_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = len_a - a->index;
		if (a->target->above_median)
			a->cost += a->target->index;
		else
			a->cost += len_b - a->target->index;
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *a)
{
	int	cheap;
	t_stack_node *current_cheap;

	cheap = a->cost;
	current_cheap = a;
	current_cheap->cheapest = true;
	a = a->next;
	while(a)
	{
		a->cheapest = false;
		if (a->cost < cheap)
		{
			current_cheap->cheapest = false;
			current_cheap = a;
			cheap = a->cost;
			current_cheap->cheapest = true;
		}
		a = a->next;
	}
}

void	refresh_a(t_stack_node *a, t_stack_node *b)
{
	refresh_index(a);
	refresh_index(b);
	refresh_target_a(a, b);
	cost_a(a, b);
	set_cheapest(a);
}
