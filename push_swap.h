/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:12:57 by apintus           #+#    #+#             */
/*   Updated: 2024/01/23 12:04:01 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h> //printf a suprr

typedef struct s_stack_node
{
	int	nbr;
	int	index;
	int	cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;

}	t_stack_node;

//PARSSING
char	*concatenate_arg(char **argv, int argc);
char	*ft_strcpy(char *dest, char *src);
int	ft_strlen(char *str);

char	**ft_split(char const *s, char c);
char	*ft_word(char const *s, char c);
int	ft_strlen_sep(char const *s, char c);
int	count_strings(char const *s, char c);
void	*ft_free(char **strs, int count);

//init_stack
void	init_stack_a(t_stack_node **a, char **argv);
void	append_node(t_stack_node **stack, int nb);
long	ft_atol(char *str);

//error
void	free_errors(t_stack_node **a);
void	free_stack(t_stack_node **stack);
int	error_duplicate(t_stack_node *a, int nb);
int	error_syntax(char	*str);

//utils
t_stack_node	*find_last(t_stack_node *stack);
bool	stack_sorted(t_stack_node *stack);
int	stack_len(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);

//commands
void	swap(t_stack_node **stack);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a,t_stack_node **b);

void	rotate(t_stack_node **stack);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);

void	reverse_rotate(t_stack_node **stack);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);

void	push(t_stack_node **src, t_stack_node **dest);
void	pa(t_stack_node **b, t_stack_node**a);
void	pb(t_stack_node **a, t_stack_node**b);


//algo
void	sort_three(t_stack_node **a);

#endif
