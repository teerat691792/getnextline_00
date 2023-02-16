# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkulket <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 11:57:28 by tkulket           #+#    #+#              #
#    Updated: 2023/02/16 21:33:17 by tkulket          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUFF = -D BUFFER_SIZE=4

FLAGS	= -Wall -Werror -Wextra

NAME	= get_next_line.a

SRC		=	get_next_line.c\
			get_next_line_utils.c\
			libft.c

OBJS := $(SRC:.c=.o)

all: $(NAME)

.c.o:
	gcc $(FLAGS) $(BUFF) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

c: re
	gcc $(FLAGS) $(BUFF) -g main.c $(NAME)
	./a.out

v: c
	valgrind --leak-check=full --show-leak-kinds=all ./a.out	

m:	re
	cd tester/ && make m
	cd ..

b:	re
	cd tester/ && make b
	cd ..

l:
	lldb a.out

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
