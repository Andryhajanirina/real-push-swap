# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 15:22:13 by andry-ha          #+#    #+#              #
#    Updated: 2026/03/12 15:14:28 by andry-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_strlen.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_strncmp.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_strnstr.c \
       ft_atoi.c \
       ft_calloc.c \
       ft_strdup.c

SRCS += ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

SRCS += ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJ_DIR     = OBJS_FILES
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
NAME = libft.a
RM = rm -rf

.PHONY: all clean fclean re

all: $(NAME)
	
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(cc) $(CFLAGS) -c $< -o $@

bonus: all

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJ_DIR)

fclean:
	$(RM) $(OBJ_DIR) $(NAME)
	@echo "The **libft** $(OBJ_DIR) and $(NAME) folder was successfully deleted."

re: fclean all