# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinpark <jinpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 10:12:35 by uamirov           #+#    #+#              #
#    Updated: 2019/08/18 03:39:40 by jinpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
INCLUDES = -I ./includes
MINILIBX = -I ./minilibx_macos -L minilibx_macos -lmlx \
			-framework OpenGL -framework AppKit
LIBFT = libft/libft.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g
SRC =	./src/fdf_main.c \
		./src/make_fdf_values_to_zero.c \
		./src/read_file_n_put_in_list.c \
		./src/count_map_size.c \
		./src/create_int_matrix.c \
		./src/fill_the_matrix.c \
		./src/create_mat_of_structures.c \
		./src/create_isometric.c \
		./src/open_window.c \
		./src/print_figure.c \
		./src/draw_line.c \
		./src/error.c

OBJ = $(SRC:.c=.o)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDES) $(MINILIBX) -o $(NAME)

clean:
	@/bin/$(RM) $(OBJ)
	@make -C libft clean

fclean: clean
	@/bin/$(RM) $(NAME)
	@make -C libft clean

re: fclean all
