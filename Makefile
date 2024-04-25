LIB_NAME = libft.a
LIBFT = ./libft/libft.a

CC = gcc
ARFLAGS = -rcs
AR = ar
CFLAGS = -Wall -Wextra -Werror

GREEN= \033[32m
COLOR_RESET = \033[0m

SRC = pipex.c ft_print_vector.c

OBJ = $(SRC:.c=.o)


all: $(LIBFT) $(LIB_NAME)
	@$(CC) $(CFLAGS) $(SRC) $(LIB_NAME)
	@echo "$(GREEN) Pipex program created!$(COLOR_RESET)"


$(LIBFT):
	$(MAKE) -C libft
	@cp libft/libft.a $(LIB_NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(LIB_NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
