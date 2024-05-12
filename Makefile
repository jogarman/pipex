NAME = pipex
LIB_NAME = libft.a
LIBFT = ./libft/libft.a
BONUS = pipex_bonus

CC = gcc
ARFLAGS = -rcs
AR = ar
CFLAGS = -Wall -Wextra -Werror

GREEN= \033[32m
COLOR_RESET = \033[0m

SRC = pipex.c execute.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = pipex_bonus.c execute_bonus.c pipex_utils_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)
$(NAME): $(LIBFT) $(LIB_NAME) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB_NAME) -o $(NAME)
	@echo "$(GREEN) Pipex program created!$(COLOR_RESET)"

bonus: $(BONUS)
$(BONUS): $(LIBFT) $(LIB_NAME) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB_NAME) -o $(BONUS)
	@echo "$(GREEN) BONUS Pipex program created!$(COLOR_RESET)"

$(LIBFT):
	$(MAKE) -C libft
	$(AR) $(ARFLAGS) $@ $(OBJ_UTILS)
	@cp libft/libft.a $(LIB_NAME)

clean:
	@rm -f $(OBJ) $(OBJ_BONUS) $(NAME) $(BONUS)
	$(MAKE) -C libft clean

fclean: clean
	@rm -f $(LIB_NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
