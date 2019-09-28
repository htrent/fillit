# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 14:40:19 by htrent            #+#    #+#              #
#    Updated: 2019/09/28 13:38:26 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit

SRCS =	fillit.c \
		funcs.c \
		input.c \
		list.c \

OBJS = $(SRCS:.c=.o)


all: $(NAME)
	./fillit file

$(NAME): $(OBJS)
		gcc -Wall -Wextra -Werror -o $(NAME) $^				-lm

$(OBJS): %.o : %.c fillit.h
		gcc -Wall -Wextra -Werror -I . -c $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
