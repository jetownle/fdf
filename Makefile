# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jetownle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/08 17:47:24 by jetownle          #+#    #+#              #
#    Updated: 2019/08/09 17:16:00 by jetownle         ###   ########.fr        #
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
	gcc $(FLAGS) -o $(NAME) $(SRCF) -I $(HDRS) -L. libft/libft.a

clean: 
	rm -rf *.o
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

debug:
	make -C libft/
	gcc -g $(FLAGS) -o $(NAME) $(SRCF) -I $(HDRS) -L. libft/libft.a

