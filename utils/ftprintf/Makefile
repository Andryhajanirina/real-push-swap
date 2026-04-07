NAME		= libftprintf.a
cc			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_PATH	=	../libft
LIBFT		=	$(LIBFT_PATH)/libft.a
OBJ_DIR     = OBJS_FILES
SRCS		= ft_printf.c \
			ft_printf_utils.c \
			ft_print_float.c \
			handle_format.c

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
RM = rm -rf

.PHONY: all clean fclean re libft

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(cc) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR)

fclean:
	make -C $(LIBFT_PATH) fclean
	$(RM) $(OBJ_DIR) $(NAME)
	@echo "The **printf** $(OBJ_DIR) and $(NAME) successfully deleted."

re: fclean all