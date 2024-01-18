/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:43:20 by apintus           #+#    #+#             */
/*   Updated: 2024/01/18 17:45:32 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last(t_stack_node *stack)
{
	if(!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
