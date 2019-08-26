# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jetownle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/08 17:47:24 by jetownle          #+#    #+#              #
#    Updated: 2019/08/26 14:01:20 by jetownle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
OBJ = *.o
SRCF = *.c
HDRS = fdf.h 

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME):
	make -C libft
	make -C minilibx
	gcc $(FLAGS) -o $(NAME) $(SRCF) -I $(HDRS) -L. libft/libft.a -L. ~/fdf/minilibx_macos/libmlx.a -framework OpenGL -framework Appkit

clean: 
	rm -rf *.o
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

debug: fclean
	make -C libft/
	make -C minilibx
	gcc -g $(FLAGS) -o $(NAME) $(SRCF) -I $(HDRS) -L. libft/libft.a -L. ~/fdf/minilibx_macos/libmlx.a -framework OpenGL -framework Appkit

