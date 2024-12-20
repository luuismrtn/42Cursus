NAME = push_swap

NAME_BONUS = checker

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

INC_DIR = ./inc

SRCS = src/main.c \
		src/move.c \
		src/sort.c \
		src/utils.c \
		src/utils2.c \
		src/turkish_sort.c \
		src/moves_a.c \
		src/count_moves_dir.c \
		src/error.c

OBJS = $(SRCS:.c=.o)

BONUSSRC = bonus/main_bonus.c \
			bonus/move_bonus.c \
			bonus/utils_bonus.c \
			bonus/error_bonus.c \
			bonus/read_bonus.c

BONUSOBJS = $(BONUSSRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBFT) $(NAME_BONUS)

$(NAME_BONUS): $(BONUSOBJS)
	$(CC) $(CFLAGS) $(BONUSOBJS) $(LIBFT) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(BONUSOBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
