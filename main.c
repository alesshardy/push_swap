/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:42:49 by apintus           #+#    #+#             */
/*   Updated: 2024/01/18 15:15:07 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	/*t_stack_node	*a;
	t_stack_node	*b;


	a = NULL;
	b = NULL;*/
	if (argc == 1)
		return (1);
	else
		argv = ft_split(concatenate_arg(argv, argc), ' ');
	/*init_stack_a(&a, all_numbers(argc, *argv));
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);*/
	int i = 0;
	while(argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
}
