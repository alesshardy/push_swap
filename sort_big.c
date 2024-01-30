/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:59:54 by apintus           #+#    #+#             */
/*   Updated: 2024/01/30 11:41:12 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_to_b(t_stack_node **a, t_stack_node **b, int median)
{
	if ((*a)->nbr < median)
		pb(a, b);
	else
	{
		pb(a, b);
		rb(b);
	}
}

void	push_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;
	t_stack_node	*temp_b;

	cheapest = NULL;
	temp_b = (*b);
	while (temp_b)
	{
		if ((temp_b)->cheapest == true)
		{
			cheapest = temp_b;
			break ;
		}
		(temp_b) = (temp_b)->next;
	}
	while (cheapest->index != 0 || cheapest->target->index != 0)
	{
		if (cheapest->above_median == true && cheapest->target->above_median == true)
		{
			while ((cheapest->index != 0 && cheapest->target->index != 0))
			{
				rr(a, b);
				refresh_index(*a);
				refresh_index(*b);
			}
			if (cheapest->index != 0)
				while (cheapest->index != 0)
				{
					rb(b);
					refresh_index(*b);
				}
			else
				while (cheapest->target->index != 0)
				{
					ra(a);
					refresh_index(*a);
				}
		}
		else if ((cheapest->above_median == false && cheapest->target->above_median == false))
		{
			while((cheapest->index != 0 && cheapest->target->index != 0))
			{
				rrr(a, b);
				refresh_index(*a);
				refresh_index(*b);
			}
			if (cheapest->index != 0)
				while (cheapest->index != 0)
				{
					rrb(b);
					refresh_index(*b);
				}
			else
				while (cheapest->target->index != 0)
				{
					rra(a);
					refresh_index(*a);
				}
		}
		else if (((cheapest->above_median == true && cheapest->target->above_median == false)))
		{
			while (cheapest->index != 0)
			{
				rb(b);
				refresh_index(*b);
			}
			while (cheapest->target->index != 0)
			{
				rra(a);
				refresh_index(*a);
			}
		}
		else
		{
			while (cheapest->index != 0)
			{
				rrb(b);
				refresh_index(*b);
			}
			while (cheapest->target->index != 0)
			{
				ra(a);
				refresh_index(*a);
			}
		}
	}
	pa(b, a);
}

void	to_the_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = find_min(*a);
	while (min->index != 0)
	{
		if (min->above_median == true)
		{
			ra(a);
			refresh_index(*a);
		}
		else
		{
			rra(a);
			refresh_index(*a);
		}
	}
}

void	sort_big(t_stack_node **a, t_stack_node **b)
{
	int	len_a;
	int	median;

	len_a = stack_len(*a);
	median = ((find_min(*a)->nbr + find_max(*a)->nbr) / 2);
	while (len_a-- > 3 && !stack_sorted(*a))
		push_a_to_b(a, b, median);
	sort_three(a);
	while (*b)
	{
		refresh(*a, *b);
		push_b_to_a(a, b);
	}
	refresh_index(*a);
	to_the_top(a);
}
