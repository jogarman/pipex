/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:30:55 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/04/27 22:45:16 by jgarcia3         ###   ########.fr       */
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
//argv[0] = nombre archivo (pipex.c)
//argv[1] = infile
//argv[2] = comando y flags

//por chat gpt. POR QUE TIENE QUE CERRAR Y ABRIR UN EXTREMO DEL PIPE?
/*  if (pid == 0)
	{ // Proceso hijo
        close(pipefd[1]); // Cerrar el descriptor de escritura del hijo

        // Leer datos del pipe
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Hijo: Recibido mensaje del padre: %s\n", buffer);

        close(pipefd[0]); // Cerrar el descriptor de lectura del hijo
    }
	else
	{ // Proceso padre
        close(pipefd[0]); // Cerrar el descriptor de lectura del padre

        const char *msg = "Hola, hijo!"; // Mensaje a enviar al hijo

        // Escribir datos en el pipe
        write(pipefd[1], msg, strlen(msg) + 1);
        printf("Padre: Mensaje enviado al hijo: %s\n", msg);

        close(pipefd[1]); // Cerrar el descriptor de escritura del padre

        // Esperar a que el hijo termine
        waitpid(pid, &status, 0);
    } */
int	main(int argc, char* argv[], char **env)
{
	(void)argc;	//eliminar
	pid_t	fork_id_1;
	pid_t	fork_id_2;
	int 	pipe_fd[2];

	fork_id_1 = fork();
	pipe(pipe_fd);
	if (fork_id_1 == 0)
	{
		exec_first_command(argv, env);
	}
	else
	{
		close(pipe_fd[0]);
		fork_id_2 = fork();
		if (fork_id_2 == 0)
		{
			exec_first_command(argv, env);
		}
		pipe_fd[1] = open("outfile", O_WRONLY); // Descriptor de escritura

	}
/* 	close(pipefd[1]); // Cerrar el descriptor de escritura del hijo

    read(pipefd[0], buffer, sizeof(buffer));

    close(pipefd[0]); // Cerrar el descriptor de lectura del hijo */
}
