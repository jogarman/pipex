/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:30:55 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/04/28 23:29:50 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	Takes array -arguments-, make malloc + 1. Copy every element,
	add last element and add NULL
*/

char	**insert_element_last_pos(char **arguments_input, char *last_element)
{
	int		i;
	char	**argument_ret;

	argument_ret = malloc((arraylen(arguments_input) + 2) * sizeof(char*));
	i = 0;
	while (arguments_input[i] != NULL)
	{
		argument_ret[i] = arguments_input[i];
		i++;
	}
	argument_ret[i] = last_element;
	argument_ret[++i] = NULL;
	return (argument_ret);
}

void	exec_first_command(char* argv[], char **env)
{
	char	*path_program;
	char	*command;
	char	**arguments;

	command = ft_split(argv[2], ' ')[0];
	path_program = ft_strjoin("/bin/", command);
	arguments = ft_split(argv[2], ' ');	// Creamos la lista para pasar a execve
	arguments = insert_element_last_pos(arguments, argv[1]); // hacer free()?
	execve(path_program, arguments, env);
}

/* 		//TESTER para ver si está bien
		int retorno_hijo;
		waitpid(fork1, &retorno_hijo, 0);
		close(tube[WRITE_TUBE]);
		char buffer[10];
		read(tube[READ_TUBE], buffer, 10);
		write(1, buffer, 10); */
/*

If  idtype  is	P_PID, waitid()	and wait6() wait for the child
		 process with a	process	ID equal to (pid_t)id. [MAN]
		 */
//argv[0] = nombre archivo (pipex.c)
//argv[1] = infile
//argv[2] = comando y flags

#define READ_TUBE	0			/*index pipe lectura*/
#define WRITE_TUBE	1			/*index pipe escritura*/
#define FILE_NAME	"outfile"

int	main(int argc, char* argv[], char **env)
{
	//(void)argc;	//eliminar
	pid_t	fork1;
	pid_t	fork2;
	int 	tube[2];

	pipe(tube);
	/////////////////////////////////////////
	fork1 = fork();					// Hijo 1

	if (fork1 == 0)
	{
		int fd_temp; //BORRAR

		fd_temp = open("infile", O_RDONLY);
		dup2(fd_temp, STDIN_FILENO);
		close(fd_temp);

		close(tube[READ_TUBE]);

 		dup2(tube[WRITE_TUBE], STDOUT_FILENO);
		close(tube[WRITE_TUBE]);

		exec_first_command(argv, env);
	}
	else
	{////////////////////////////////////////////
   		fork2 = fork(); 			// Hijo 2 //
		if (fork2 == 0)
		{
			int fd_temp;
			fd_temp = open("outfile", O_WRONLY);
			dup2(fd_temp, STDOUT_FILENO);
			close(fd_temp);

			close(tube[WRITE_TUBE]);
			dup2(tube[READ_TUBE], STDOUT_FILENO);
			close(tube[STDOUT_FILENO]);
			char *args_execve[] = {"wc", "-w" "outfile", NULL};
			execve("/bin/wc", args_execve, env);
		}
		////////////////////////////////////////
									// Padre //
		int retorno_hijo;
		waitpid(fork1, &retorno_hijo, 0);
		close(tube[WRITE_TUBE]);
		dup2(tube[READ_TUBE], )



	}
	return (0);
}
