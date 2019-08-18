NAME = fdf
INCLUDES = -I ./includes
MINILIBX = -I ./minilibx_macos -L minilibx_macos -lmlx \
			-framework OpenGL -framework AppKit
LIBFT = libft/libft.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
SRC = main.c algo_part.c print_part.c draw_and_print.c

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