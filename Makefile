# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apintus <apintus@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 17:16:05 by apintus           #+#    #+#              #
#    Updated: 2024/01/26 16:26:08 by apintus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
MAKE_LIB = ar -rcs

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(ARCHIVE)
	$(CC) $< -o $@

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	rm -f $(OBJS) $(ARCHIVE)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclea re
