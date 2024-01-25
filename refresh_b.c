/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:14:07 by apintus           #+#    #+#             */
/*   Updated: 2024/01/25 17:29:16 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refresh_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match) //the closest BIGGER nbr
			{
				best_match = current_a->nbr;
				//printf("SIUUUUU {%ld} ", best_match);
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		//printf(" NEXT ");
		b = b->next;
	}
}

void	refresh_b(t_stack_node *b, t_stack_node *a)
{
	refresh_index(a);
	refresh_index(b);
	refresh_target_a(a, b);
}
