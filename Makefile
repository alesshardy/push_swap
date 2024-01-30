# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apintus <apintus@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 17:16:05 by apintus           #+#    #+#              #
#    Updated: 2024/01/26 14:17:05 by apintus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################################
## SOURCES

SRCS =	concatenate_arg.c\
		error.c\
		ft_split.c\
		init_stack.c\
		main.c\
		refresh_b.c\
		refresh.c\
		reverse_rotate.c\
		sort_big.c\
		sort_three.c\
		swap.c\
		utils_stack.c\
		visulalize_stack.c\

OBJS =	$(SRCS:.c=.o)

#######################################################
## ARGUMENTS

CC = cc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap.a

########################################################
## RULES

all:	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
