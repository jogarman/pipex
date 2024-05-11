NAME = pipex
LIB_NAME = libft.a
LIBFT = ./libft/libft.a

CC = gcc
ARFLAGS = -rcs
AR = ar
CFLAGS = -g -Wall -Wextra -Werror

GREEN= \033[32m
COLOR_RESET = \033[0m

SRC = pipex.c execute.c

OBJ = $(SRC:.c=.o)

all: $(NAME)														# significa que compile pipex.o
$(NAME): $(LIBFT) $(LIB_NAME) $(OBJ) $(OBJ_UTILS) # si no ex. crealo  # -o $(NAME) en linea de abajo. Parece que sobra
	@$(CC) $(CFLAGS) $(OBJ) $(LIB_NAME) -o $(NAME)
	@echo "$(GREEN) Pipex program created!$(COLOR_RESET)"

$(LIBFT):
	$(MAKE) -C libft
	$(AR) $(ARFLAGS) $@ $(OBJ_UTILS)
	@cp libft/libft.a $(LIB_NAME)

clean:
	@rm -f $(OBJ) $(OBJ_UTILS)
	$(MAKE) -C libft clean

fclean: clean
	@rm -f $(LIB_NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
