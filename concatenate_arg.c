/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:37:54 by apintus           #+#    #+#             */
/*   Updated: 2024/01/29 17:45:34 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

char	*ft_strcpy(char *dest, char *src)

{
	while(*src)
		*dest++ = *src++;
	*dest = ' ';
	return (dest);
}

char	*concatenate_arg(char **argv, int argc)
{
	int	i;
	size_t	len;
	size_t	current_index;
	char	*combined_arg;

	i = 0;
	len = 0;
	while(++i < argc)
		len = len + (ft_strlen(argv[i]) + 1);
	combined_arg = (char *)malloc(sizeof(char) * len + 1);
	if (combined_arg == NULL)
		return (NULL);
	current_index = 0;
	i = 0;
	while (++i < argc)
	{
		ft_strcpy(combined_arg + current_index, argv[i]);
		current_index += (ft_strlen(argv[i]) + 1);
	}
	combined_arg[current_index] = '\0';
	//printf("(%s)\n\n", combined_arg); // a retirer
	return (combined_arg);
}
