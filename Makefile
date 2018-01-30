# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 18:09:32 by omakovsk          #+#    #+#              #
#    Updated: 2017/11/24 13:38:47 by omakovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = gcc -Wall -Werror -Wextra

SRC = solve_tet.c add_func.c check_file.c make_square.c write_tets.c

OBJ = $(SRC:.c=.o)

all: $(SRC) $(NAME)

$(NAME): $(OBJ)
	$(FLAGS) $^ -o $@

%.o: %.c
	$(FLAGS) -c $< 

clean:
	rm -f $(OBJ)
	@echo files deleted -_-

fclean: clean
	rm -f $(NAME)
	@echo testfillit deleted -_-

re: fclean all

.PHONY: clean fclean all re
