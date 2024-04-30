#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h> // para leer y escribir
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"


int		arraylen(char **array);
int		ft_print_vector(char **vector);
//# include "utils/ft_print_vector.c" //utils
//# include "utils/arraylen.c" //utils


#endif