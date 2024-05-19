NAME = pipex
LIBFT = ./libft/libft.a
BONUS = pipex_bonus

CC = gcc
ARFLAGS = -rcs
AR = ar
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize="address"

GREEN= \033[32m
COLOR_RESET = \033[0m

SRC = pipex.c execute.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = pipex_bonus.c execute_bonus.c pipex_utils_bonus.c here_doc.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)
$(NAME): $(LIBFT) $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN) Pipex program created!$(COLOR_RESET)"

bonus: $(BONUS)
$(BONUS): $(LIBFT) $(LIBFT) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS)
	@echo "$(GREEN) BONUS Pipex program created!$(COLOR_RESET)"

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	@rm -f $(OBJ) $(OBJ_BONUS) $(NAME) $(BONUS)
	$(MAKE) -C libft clean

fclean: clean
	@rm -f $(LIBFT)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
