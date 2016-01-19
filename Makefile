# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adespond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 14:14:20 by adespond          #+#    #+#              #
#    Updated: 2016/01/19 15:42:09 by rdidier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

SRC		=	includes/get_next_line/get_next_line.c	\
			sources/main.c

OBJ		=	$(patsubst src/%.c,./%.o,$(SRC))

MAP		=	maps/temp

.SILENT:

$(NAME): $(OBJ)
	gcc -Wall -Werror -Wextra $(OBJ) -L includes/libft/ -lft -o $(NAME)
	printf '\033[4m'
	printf '\033[32m[ ✔ ] %s\n\033[0m' "fdf is done !"
./%.o: src/%.c
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf *.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

javel:
	clear

boom : javel $(NAME) clean
	./fdf $(MAP)

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
