NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PLAYER_DIR = /player
MAP_DIR = /map
CHECKER_DIR = /checker

SRCS = ./src/main.c \
		./src$(PLAYER_DIR)/move_player.c \
		./src$(MAP_DIR)/load_map.c \
		./src$(MAP_DIR)/draw_map.c \
		./src$(CHECKER_DIR)/checker.c \
		./src$(CHECKER_DIR)/checker_extra.c \
		./src$(CHECKER_DIR)/dfs.c  \
		./src$(CHECKER_DIR)/dfs_extra.c \

OBJS = $(SRCS:.c=.o)

BONUSSRC = ./bonus/main_bonus.c \
		./bonus$(PLAYER_DIR)/move_player_bonus.c \
		./bonus$(MAP_DIR)/load_map_bonus.c \
		./bonus$(MAP_DIR)/draw_map_bonus.c \
		./bonus$(CHECKER_DIR)/checker_bonus.c \
		./bonus$(CHECKER_DIR)/checker_extra_bonus.c \
		./bonus$(CHECKER_DIR)/dfs_bonus.c  \
		./bonus$(CHECKER_DIR)/dfs_extra_bonus.c \

BONUSOBJ = $(BONUSSRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

MINILIBX := ./mlx
MLX_HEADERS := -I$(MINILIBX) -I./inc

LIBRARY := -L$(MINILIBX) -lmlx -lX11 -lXext -lXrender -lXrandr

all: $(NAME)

$(MINILIBX)/libmlx.a:
	make -C $(MINILIBX)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBRARY) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_HEADERS) -c $< -o $@

bonus: $(BONUSOBJ) $(LIBFT) $(MINILIBX)/libmlx.a
	$(CC) $(CFLAGS) $(BONUSOBJ) $(LIBFT) $(LIBRARY) -o $(NAME)_bonus

clean:
	rm -f $(OBJS)
	rm -f $(BONUSOBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME)_bonus
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
