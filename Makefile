NAME = pipex
LIBFT = ./libft/libft.a
BONUS = pipex_bonus

CC = gcc
ARFLAGS = -rcs
AR = ar
CFLAGS = -Wall -Wextra -Werror

GREEN= \033[32m
COLOR_RESET = \033[0m


OBJ = $(SRC:.c=.o)

SRC = pipex.c execute_bonus.c pipex_utils_bonus.c here_doc.c \
	first_fork_bonus.c last_fork_bonus.c mid_fork_loop_caller_bonus.c

SRC_BONUS = pipex_bonus.c execute_bonus.c pipex_utils_bonus.c here_doc.c \
	first_fork_bonus.c last_fork_bonus.c mid_fork_loop_caller_bonus.c

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
