/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visulalize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:08:06 by apintus           #+#    #+#             */
/*   Updated: 2024/01/25 16:01:01 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visual_stack(t_stack_node *a, t_stack_node *b)
{
	printf("[a]	[b]\n");
	while (a || b)
	{
		if (a == NULL)
			printf("-\t");
		else
			printf("{%d}\t", a->nbr);
		if (b == NULL)
			printf("-\n");
		else
			printf("{%d}\n", b->nbr);
		if (a)
			a = a->next;
		if (b)
		b = b->next;
	}
	printf("\n");
}
