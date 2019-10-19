# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 14:40:19 by htrent            #+#    #+#              #
#    Updated: 2019/10/19 14:23:08 by hcaterpi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit

SRCS =	fillit.c \
		funcs.c \
		input.c \
		list.c \
		field.c \
		shift.c \
		solve.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
		gcc -Wall -Wextra -Werror -o $(NAME) $^

$(OBJS): %.o : %.c fillit.h
		gcc -Wall -Wextra -Werror -I . -c $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
