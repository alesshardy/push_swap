/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:59:54 by apintus           #+#    #+#             */
/*   Updated: 2024/01/22 16:47:54 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		refresh_node_a(*a, *b);
		push_a_to_b(a, b);
	}
	sort_three(a);
	while(b)
	{
		refresh_node_b(*a, *b);
		push_b_to_a(a, b);
	}
	refresh_index(*a);
	min_on_top(a);
}
