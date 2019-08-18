NAME = fdf
INCLUDES = -I ./includes
MINILIBX = -I ./minilibx_macos -L minilibx_macos -lmlx \
			-framework OpenGL -framework AppKit
LIBFT = libft/libft.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g
SRC = main.c

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