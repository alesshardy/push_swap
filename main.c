/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:42:49 by apintus           #+#    #+#             */
/*   Updated: 2024/01/30 11:26:52 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*one_arg;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else
	{
		one_arg = concatenate_arg(argv, argc);
		argv = ft_split(one_arg, ' ');
	}
	free(one_arg);
	init_stack_a(&a, argv);
	ft_free(argv, argc);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_big(&a, &b);
	}
	free_stack(&a);
	return (0);
}
