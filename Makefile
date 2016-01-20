# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adespond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 14:14:20 by adespond          #+#    #+#              #
#    Updated: 2016/01/20 13:21:27 by rdidier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

SRC		=	includes/get_next_line/get_next_line.c	\
			sources/main.c							\
			sources/read_stuff.c					\
			sources/window.c						\
			sources/pixels.c						\
			sources/draw.c							\

OBJ		=	$(patsubst src/%.c,./%.o,$(SRC))

FLAG	=	-Wall -Werror -Wextra -framework OpenGL -framework AppKit

MAP		=	maps/42.fdf

.SILENT:

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) -I /usr/X11/include -g -L/usr/X11/lib \
		-lmlx -lXext -lX11 -L includes/libft/ -lft -o $(NAME)
	printf '\033[4m'
	printf '\033[32m[ ✔ ] %s\n\033[0m' "fdf is done !"
./%.o: src/%.c
	gcc $(FLAG) -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf *.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

javel:
	clear

boom : javel fclean $(NAME) clean
	./fdf $(MAP)

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
