/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:59:54 by apintus           #+#    #+#             */
/*   Updated: 2024/01/29 14:29:03 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	push_a_to_b(t_stack_node **a,t_stack_node **b)
{
	t_stack_node *cheapest;
	t_stack_node *tempA;

	cheapest = NULL;
	tempA = (*a);
	while(tempA)
	{
		if ((tempA)->cheapest == true)
		{
			cheapest = tempA;
			//printf("CHEAP [%d] CHEAP\n", (tempA)->nbr);
			//printf("TARGET [%d] TARGET\n", (tempA)->target->nbr);
			break;
		}
		(tempA) = (tempA)->next;
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
	pb(a, b);
}

void	push_b_to_a(t_stack_node **a,t_stack_node **b)
{
	t_stack_node *target;

	target = (*b)->target;
	//printf("TARGET [%d] TARGET\n", target->nbr);
	while (target->index != 0)
	{

		if (target->above_median == true)
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
	pa(b, a);
}

void	to_the_top(t_stack_node **a)
{
	t_stack_node *min;

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

	len_a = stack_len(*a);
	//visual_stack(*a, *b);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	//visual_stack(*a, *b);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	//visual_stack(*a, *b); //a suprrimer
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		//visual_stack(*a, *b); //a suprrimer
		refresh_a(*a, *b);
		push_a_to_b(a, b);
	}
	//visual_stack(*a, *b); //a suprrimer
	//printf("HELLO\n");
	sort_three(a);
	//visual_stack(*a, *b); //a suprrimer
	while(*b)
	{
		//visual_stack(*a, *b); //a suprrimer
		refresh_b(*a, *b);
		push_b_to_a(a, b);
	}
	refresh_index(*a);
	to_the_top(a);
	//visual_stack(*a, *b); //a suprrimer
}
