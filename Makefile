LIB_NAME = libft.a
LIBFT = ./libft/libft.a
NAME = pipex

CC = gcc
ARFLAGS = -rcs
AR = ar
CFLAGS = -Wall -Wextra -Werror

GREEN= \033[32m
COLOR_RESET = \033[0m

SRC = $(NAME).c
SRC_UTILS = $(wildcard utils/*.c) $(wildcard utils/exec/*.c)
#SRC_UTILS = $(addprefix utils/, ft_print_vector.c arraylen.c path_array.c ) #elimar print__vector

OBJ = $(SRC:.c=.o)
OBJ_UTILS = $(SRC_UTILS:.c=.o)

all: $(NAME)														# significa que compile pipex.o
$(NAME): $(LIBFT) $(LIB_NAME) $(OBJ) $(OBJ_UTILS) # si no ex. crealo  # -o $(NAME) en linea de abajo. Parece que sobra
	@$(CC) $(CFLAGS) $(OBJ)  $(SRC_UTILS)  $(LIB_NAME) -o $(NAME)
	@echo "$(GREEN) Pipex program created!$(COLOR_RESET)"
#ojoo en la linea de compilacion el -g!!!

$(LIBFT): $(OBJ_UTILS)
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
