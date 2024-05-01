#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h> // para leer y escribir
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>


# include "libft/libft.h"
//# include "libft/ft_printf/ft_printf.h"
//# include "libft/get_next_line/get_next_line.h"

# define READ_TUBE	0			/*index pipe lectura*/
# define WRITE_TUBE	1			/*index pipe escritura*/
# define OUTFILE	argv[4]
# define INFILE		argv[1]

int		arraylen(char **array);
int		ft_print_vector(char **vector);  //ELIMINAR: CONTIENE PRINTF
int		access_to_file(char* argv);
//int     args_are_ok(argc);

#endif