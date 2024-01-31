# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apintus <apintus@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 17:16:05 by apintus           #+#    #+#              #
#    Updated: 2024/01/31 11:42:41 by apintus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################################################
## ARGUMENTS

NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g
MAKE_LIB = ar -rcs

##########################################################
## SOURCES

SRCS = concatenate_arg.c\
				error.c\
				ft_split.c\
				init_stack.c\
				main.c\
				push_b_to_a.c\
				push.c\
				refresh.c\
				reverse_rotate.c\
				rotate.c\
				sort_big.c\
				sort.c\
				swap.c\
				utils_stack.c\

OBJS = $(SRCS:.c=.o)

##########################################################
## RULES

all : $(NAME)

$(NAME) : $(ARCHIVE)
	$(CC) $(ARCHIVE) -o $(NAME)

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	$(RM) $(OBJS) $(ARCHIVE)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
