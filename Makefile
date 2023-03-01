# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 15:28:14 by lliberal          #+#    #+#              #
#    Updated: 2023/03/01 17:13:46 by lliberal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
NAME	=	push_swap
INCLUDE	=	push_swap.h
SRCS	=	push_swap.c \
			util.c \
			create_stack.c
OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I $(INCLUDE)

clean:
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)
re:	fclean all

.PHONY:	all clean fclean re
