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

BONUSSRC = bonus/main.c \
			bonus/move.c \
			bonus/utils.c \
			bonus/error.c \
			bonus/read.c

BONUSOBJS = $(BONUSSRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c $(INC_DIR)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(INC_DIR)/push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS) $(BONUSOBJS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUSOBJS) $(LIBFT)

clean:
	rm -f $(OBJS) $(BONUSOBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
