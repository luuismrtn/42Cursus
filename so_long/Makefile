NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PLAYER_DIR = ./player
MAP_DIR = ./map
CHECKER_DIR = ./checker

SRCS = main.c \
		$(PLAYER_DIR)/move_player.c \
		$(MAP_DIR)/load_map.c $(MAP_DIR)/draw_map.c \
		$(CHECKER_DIR)/checker.c $(CHECKER_DIR)/checker_extra.c $(CHECKER_DIR)/dfs.c  $(CHECKER_DIR)/dfs_op.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

MINILIBX := ./minilibx-linux

MLX_HEADERS := -I$(MINILIBX) -I.

LIBRARY := -L$(MINILIBX) -lmlx -lX11 -lXext -lXrender -lXrandr

all: $(NAME)


$(MINILIBX)/libmlx.a:
	make -C $(MINILIBX)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBRARY) -o $(NAME)


$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(MLX_HEADERS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
