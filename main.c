/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:42:49 by apintus           #+#    #+#             */
/*   Updated: 2024/01/19 15:22:42 by apintus          ###   ########.fr       */
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
	printf("\n");

	init_stack_a(&a, argv);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		/*else
			sort_stacks(&a, &b);*/
	}

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

	free_stack(&a);
}
