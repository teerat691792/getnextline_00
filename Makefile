# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkulket <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 11:57:28 by tkulket           #+#    #+#              #
#    Updated: 2023/02/20 20:49:28 by tkulket          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUFF = -D BUFFER_SIZE=4 

FLAGS	= -Wall -Werror -Wextra

NAME	= get_next_line.a

NAMEBONUS	= get_next_line_bonus.a

SRC		=	get_next_line.c\
			get_next_line_utils.c

BONUS	=	get_next_line_bonus.c\
			get_next_line_utils_bonus.c

OBJS := $(SRC:.c=.o)
OBJSBONUS := $(BONUS:.c=.o)

all: $(NAME) $(NAMEBONUS)

.c.o:
	gcc $(FLAGS) $(BUFF) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(NAMEBONUS): $(OBJSBONUS)
	ar -rcs $(NAMEBONUS) $(OBJSBONUS)

cm: re
	gcc $(FLAGS) $(BUFF) -g main.c $(NAME)
	./a.out

cb: re
	gcc $(FLAGS) $(BUFF) -g main.c $(NAMEBONUS)
	./a.out

v: c
	valgrind --leak-check=full --show-leak-kinds=all ./a.out

vb: cb
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
	rm -f $(OBJSBONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMEBONUS)

re: fclean all

.PHONY: all clean fclean re
