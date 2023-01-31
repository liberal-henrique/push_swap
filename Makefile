# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 15:28:14 by lliberal          #+#    #+#              #
#    Updated: 2023/01/30 11:35:10 by lliberal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

INCLUDE	=	push_swap.h

RM		=	rm -f

SRCS	=	push_swap.c \
			util.c \
			create_stack.c

OBJS	=	$(SRCS:.c=.o)


all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I $(INCLUDE)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) *.o

re:	fclean all

.PHONY:	all clean fclean re
