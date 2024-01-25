/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:59:54 by apintus           #+#    #+#             */
/*   Updated: 2024/01/25 17:38:16 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_to_b(t_stack_node **a,t_stack_node **b)
{
	t_stack_node *cheapest;

	while(*a)
	{
		if ((*a)->cheapest == true)
		{
			cheapest = *a;
			printf("CHEAP [%d] CHEAP\n", (*a)->nbr);
			printf("TARGET [%d] TARGET\n", (*a)->target->nbr);
			break;
		}
		(*a) = (*a)->next;
	}
	while (cheapest->index != 0 || cheapest->target->index != 0)
	{
		if(cheapest->above_median == true && cheapest->target->above_median == true)
		{
			while((cheapest->index != 0 && cheapest->target->index != 0))
			{
				rr(a, b);
				refresh_index(*a);
				refresh_index(*b);
			}
			if (cheapest->index != 0)
				while (cheapest->index != 0)
				{
					ra(a);
					refresh_index(*a);
				}
			else
				while (cheapest->target->index != 0)
				{
					rb(b);
					refresh_index(*b);
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
					rra(a);
					refresh_index(*a);
				}
			else
				while (cheapest->target->index != 0)
				{
					rrb(b);
					refresh_index(*b);
				}
		}
		else if (((cheapest->above_median == true && cheapest->target->above_median == false)))
		{
			while (cheapest->index != 0)
			{
					ra(a);
					refresh_index(*a);
			}
			while (cheapest->target->index != 0)
			{
					rrb(b);
					refresh_index(*b);
			}
		}
		else
		{
			while (cheapest->index != 0)
			{
					rra(a);
					refresh_index(*a);
			}
			while (cheapest->target->index != 0)
			{
					rb(b);
					refresh_index(*b);
			}
		}
	}
	pa(a, b);
}

void	push_b_to_a(t_stack_node **a,t_stack_node **b)
{
	t_stack_node *cheapest;

	while(*b)
	{
		if ((*b)->cheapest == true)
		{
			cheapest = *b;
			printf("CHEAP [%d] CHEAP\n", (*b)->nbr);
			printf("TARGET [%d] TARGET\n", (*b)->target->nbr);
			break;
		}
		(*b) = (*b)->next;
	}
	while (cheapest->index != 0 || cheapest->target->index != 0)
	{
		if(cheapest->above_median == true && cheapest->target->above_median == true)
		{
			while((cheapest->index != 0 && cheapest->target->index != 0))
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
	pb(b, a);
}

void	sort_big(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	visual_stack(*a, *b);
	if (len_a-- > 3 && !stack_sorted(*a))
		pa(a, b);
	visual_stack(*a, *b);
	if (len_a-- > 3 && !stack_sorted(*a))
		pa(a, b);
	visual_stack(*a, *b); //a suprrimer
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		visual_stack(*a, *b); //a suprrimer
		refresh_a(*a, *b);
		push_a_to_b(a, b);
	}
	sort_three(a);
	visual_stack(*a, *b); //a suprrimer
	while(b)
	{
		visual_stack(*a, *b); //a suprrimer
		refresh_b(*a, *b);
		push_b_to_a(a, b);
	}
	refresh_index(*a);
	/*min_on_top(a);*/
}
