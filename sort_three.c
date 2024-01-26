/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:23:55 by apintus           #+#    #+#             */
/*   Updated: 2024/01/26 18:13:49 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*higher;

	higher = find_max(*a);
	printf("%d\n", higher->nbr);
	if (higher == *a)
	{
		ra(a);
		visual_stack(*a, *a);
	}
	else if ((*a)->next == higher)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

/*int		sort_three(t_stack_node **a)
{
	t_stack_node	*min;
	t_stack_node	*max;
	refresh_index(*a);
	min = find_min(*a);
	max = find_max(*a);
	if (min->index == 0 && max->index == 1)
		return (rra(a), sa(a), 1);
	if (min->index == 1 && max->index == 2)
		return (sa(a), 1);
	if (min->index == 2 && max->index == 1)
		return (rra(a), 1);
	if (min->index == 2 && max->index == 0)
		return (ra(a), sa(a), 1);
	if (min->index == 1 && max->index == 0)
		return (ra(a), 1);
	return (1);
}*/
