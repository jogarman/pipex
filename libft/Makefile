NAME = libft.a
CC = cc
AR = ar
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror
PRINTF_ADDR = ./ft_printf
GNL_ADDR = ./get_next_line


GREEN= \033[32m
COLOR_RESET = \033[0m

SRC_LIBFT = ft_atoi.c ft_isdigit.c ft_memmove.c ft_strlen.c \
ft_toupper.c ft_bzero.c   ft_isprint.c ft_memset.c \
ft_strncmp.c ft_isalnum.c ft_memchr.c  ft_strchr.c \
ft_strnstr.c ft_isalpha.c ft_memcmp.c  ft_strlcat.c \
ft_strrchr.c ft_isascii.c ft_memcpy.c  ft_strlcpy.c ft_tolower.c \
\
ft_calloc.c ft_strdup.c \
\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c \
\
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRC_PRINTF = $(PRINTF_ADDR)/ft_printf.c $(PRINTF_ADDR)/ft_dec_to_hex.c \
	$(PRINTF_ADDR)/ft_putunsgnbr_fd.c $(PRINTF_ADDR)/ft_convertor.c \
	$(PRINTF_ADDR)/ft_convertor2.c
SRC_GNL = $(GNL_ADDR)/get_next_line.c $(GNL_ADDR)/get_next_line_utils.c
SRC_TO_DEL = $(PRINTF_ADDR)/ft_dec_to_hex.c \
	$(PRINTF_ADDR)/ft_putunsgnbr_fd.c $(PRINTF_ADDR)/ft_convertor.c \
	$(PRINTF_ADDR)/ft_convertor2.c $(GNL_ADDR)/get_next_line_utils.c

OBJ = $(SRC_LIBFT:.c=.o)
OBJ += $(SRC_PRINTF:.c=.o)
OBJ += $(SRC_GNL:.c=.o)

all: $(NAME)
$(NAME): $(PRINTF_ADDR) $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "$(GREEN) Libft objects and $(NAME) succesfully done!$(COLOR_RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(GREEN)clean succesful!$(COLOR_RESET)"

fclean:
	@rm -f $(NAME) $(OBJ)
	@echo "$(GREEN)fclean succesful!$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re