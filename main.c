/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:42:49 by apintus           #+#    #+#             */
/*   Updated: 2024/01/18 18:19:42 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;


	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else
		argv = ft_split(concatenate_arg(argv, argc), ' ');
	int i = 0;
	while(argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	init_stack_a(&a, argv); //voir le plus 1?
	/*if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);*/
	printf("\n");
	t_stack_node	*tmp;
	t_stack_node	*current;

	current = a;
	while(current)
	{
	tmp = current->next;
	printf("%d\n", current->nbr);
	current = tmp;
	}
}
