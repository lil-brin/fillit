# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmuravio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/18 13:58:30 by vmuravio          #+#    #+#              #
#    Updated: 2018/01/18 14:03:07 by vmuravio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBNAME = libft/libft.a

SRC = src/ft_field.c src/ft_get_coord.c src/ft_read.c src/ft_valid.c \
	  src/ft_move_tetro.c src/main.c src/ft_manipulations.c src/ft_solver.c

INC = -I src/

OBJ = $(SRC:.c=.o)

LIBOBJ = make -C libft/

FLAGS = -Wall -Wextra -Werror

CFLAGS = -c $(FLAGS)

all: liball $(NAME)

obj: $(OBJ)

$(NAME) : $(LIBNAME) $(OBJ)
		gcc $(FLAGS) $^ -o $(NAME)

%.o: %.c
		gcc $(CFLAGS) -o $@ $<

clean: libclean
		rm -rf $(OBJ)

fclean: libfclean clean
		rm -rf $(NAME)

re: fclean all

$(LIBNAME): liball

liball:
		@make -C libft/ all

libclean:
		@make -C libft/ clean

libfclean:
		@make -C libft/ fclean

libre: libfclean liball
