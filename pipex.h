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
# define COMMAND_1  argv[2]
# define COMMAND_2  argv[3]

#endif

int		arraylen(char **array);
int		ft_print_vector(char **vector);  //ELIMINAR: CONTIENE PRINTF
char	**path_array(char **env);
char	*where_is_comm(char *command, char **env);

/* 
int     args_are_ok(int argc);
void	child2(char* argv[], char **env, int tube[2]);
void	child1(char* argv[], char **env, int tube[2]);
void	exec_first_command(char* argv[], char **env);
char	**insert_element_last_pos(char **arguments_input, char *last_element);
void	exec_second_command(char* argv[], char **env); */

