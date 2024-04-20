NAME = libftprintf.a
LIBFTPRINTF = ./printf/libftprintf.a
CC = gcc
ARFLAGS = -rcs

CFLAGS = -Wall -Wextra -Werror

SRC = #####

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFTPRINTF) $(OBJ)
	ar $(ARFLAGS) $(NAME) $(OBJ)

####
$(LIBFTPRINTF):
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)

clean:
	rm -f $(OBJ)
####
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
####
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
