NAME		= fdf

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
CFLAGS		+= -I includes -I src/libft/includes
LDFLAGS		+= -L src/libft/ -lft -L src/minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

DLIBFT	:= src/libft
LIBFT	:= src/libft/libft.a
DLIBMLX	:= src/minilibx_macos
LIBMLX	:= src/minilibx_macos/libmlx.a

DSRC	= ./src/src
DOBJF	= ./src/obj
DINC	= ./src/inc

SRC		:= $(shell ls -1 $(DSRC) | grep .c$$)
OBJF	:= $(SRC:.c=.o)
OBJF	:= $(addprefix $(DOBJF)/, $(OBJF))


all: $(NAME)

$(LIBFT):
	@make -C ./src/libft
	
$(LIBMLX):
	@make -C ./src/minilibx_macos
	
$(DOBJF)/%.o: $(DSRC)/%.c $(DINC)
	@mkdir -p $(DOBJF)
	@gcc -c $(CFLAGS) $< -o $@

$(NAME): $(LIBFT) $(LIBMLX) $(OBJF)
	@gcc -L src/libft/ -lft -L src/minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -o $@ $^
	
clean:
	@rm -rf $(OBJF)
	@make -C $(DLIBFT) clean
	@make -C $(DLIBMLX) clean
	
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(DOBJF)
	@make -C $(DLIBFT) fclean
	
re: fclean all