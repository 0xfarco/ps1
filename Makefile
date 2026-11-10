NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I include

SRC_DIR = src
OBJ_DIR = obj

SRCS    = main.c parse_args.c parse_int.c parse_utils.c \
          stack.c stack_ops.c stack_utils.c ctx.c utils.c \
          ops_swap.c ops_push.c ops_rotate.c ops_rrotate.c ops_multi.c ops_emit.c \
          moves.c rank.c strategy.c bench.c \
          sort_simple.c sort_chunk.c sort_radix.c \
          sort_window.c

OBJS    = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/push_swap.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
