/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:23:55 by apintus           #+#    #+#             */
/*   Updated: 2024/01/29 11:23:25 by apintus          ###   ########.fr       */
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

