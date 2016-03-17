# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adespond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 14:14:20 by adespond          #+#    #+#              #
#    Updated: 2016/03/17 10:31:17 by rdidier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

SRC		=	sources/main.c							\
			sources/read_file.c						\
			sources/window.c						\
			sources/pixels.c						\
			sources/draw.c							\
			sources/camera.c						\
			sources/matrix.c						\
			sources/matrix_2.c						\
			sources/map.c							\

OBJ		=	$(patsubst src/%.c,./%.o,$(SRC))

FLAG	=	-Wall -Werror -Wextra -framework OpenGL -framework AppKit

MAP		=	maps/pentenegpos.fdf

.SILENT:

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAG) $(OBJ)  -L/usr/local/lib -L libft/ -lft -lmlx  -o $(NAME)
	printf '\033[4m'
	printf '\033[32m[ ✔ ] %s\n\033[0m' "fdf is done !"
./%.o: src/%.c
	gcc $(FLAG) -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	make -C libft/ clean
	/bin/rm -rf *.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

javel:
	clear

boom : javel fclean $(NAME) clean
	./fdf $(MAP)

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
