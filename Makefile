NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

FT_PRINTF_PATH  = ./utils/ftprintf
FT_PRINTF       = $(FT_PRINTF_PATH)/libftprintf.a

OBJ_DIR     = OBJS_FILES

SRCS        = push_swap.c

SRCS        += operations/push.c \
			operations/reverse_rotate.c \
			operations/rotate.c \
			operations/swap.c

SRCS        += parsing/check_numbers.c \
			parsing/check_duplicates.c \
			parsing/parse_args.c

SRCS        += algo/cost_to_top.c \
			algo/find_min_pos.c \
			algo/best_move.c \
			algo/target_pos.c

SRCS        += bench/print_strategy.c \
			bench/print_bench_stats.c

SRCS        += sorting/index_stack.c \
			sorting/complex_sort.c \
			sorting/sort_3.c \
			sorting/sort_5.c \
			sorting/simple_sort.c \
			sorting/medium_sort.c

SRCS        += utils/free_stack.c \
			utils/ft_atoi_safe.c \
			utils/compute_disorder.c \
			utils/find_min_max.c \
			utils/stack_utils.c

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

.PHONY: all clean fclean re libftprintf
RM          = rm -rf

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)

$(FT_PRINTF):
	make -C $(FT_PRINTF_PATH) all

clean:
	make -C $(FT_PRINTF_PATH) clean
	$(RM) $(OBJ_DIR)

fclean:
	make -C $(FT_PRINTF_PATH) fclean
	$(RM) $(OBJ_DIR) $(NAME)
	@echo "The **PUSH SWAP** $(OBJ_DIR) and $(NAME) successfully deleted."

re: fclean all
