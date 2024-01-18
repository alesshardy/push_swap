/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:12:57 by apintus           #+#    #+#             */
/*   Updated: 2024/01/18 15:17:33 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

char	*concatenate_arg(char **argv, int argc);
char	*ft_strcpy(char *dest, char *src);
int	ft_strlen(char *str);

char	**ft_split(char const *s, char c);
char	*ft_word(char const *s, char c);
int	ft_strlen_sep(char const *s, char c);
int	count_strings(char const *s, char c);
void	*ft_free(char **strs, int count);


#endif
