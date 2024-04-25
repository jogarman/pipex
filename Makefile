LIB_NAME = libft.a
LIBFT = ./libft/libft.a
NAME = pipex

CC = gcc
ARFLAGS = -rcs
AR = ar
CFLAGS = -Wall -Wextra -Werror

GREEN= \033[32m
COLOR_RESET = \033[0m

SRC = pipex.c
SRC_UTILS = $(addprefix utils/, ft_print_vector.c arraylen.c)

OBJ = $(SRC:.c=.o)
OBJ_UTILS = $(SRC_UTILS:.c=.o)

all: $(NAME)
$(NAME): $(LIBFT) $(LIB_NAME) $(OBJ) $(OBJ_UTILS) # si no exiten crealo
	$(CC) $(CFLAGS) $(SRC) $(SRC_UTILS) $(LIB_NAME) -o $(NAME)
	@echo "$(GREEN) Pipex program created!$(COLOR_RESET)"


$(LIBFT):
	$(MAKE) -C libft
	@cp libft/libft.a $(LIB_NAME)

clean:
	@rm -f $(OBJ) $(OBJ_UTILS)
	$(MAKE) -C libft clean

fclean: clean
	@rm -f $(LIB_NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
