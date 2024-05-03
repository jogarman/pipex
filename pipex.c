/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:30:55 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/03 20:19:56 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* SE  QUEDA COLGADO. eL FALLO ESTA POSIBLEMENTE EN EL SEGUNODO HIJO
GRACE DIE QUE HAY QUE BUSCAR EN  EL PATH DONDE ESTA EL PROGRAMA QUE ESTAMOS
BUSCANDO Y VER CON ACESS QUE TENEMOS PROVILEGIOS DE EJECUCION*/
/*
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
	write(2, "exec_first_command", 15);
	execute(2, argv, env);

}

void	exec_second_command(char* argv[], char **env)
{
	write(2, "nada", 4);
}

void	child1(char* argv[], char **env, int tube[2])
{
	int fd_temp;
	fd_temp = open(INFILE, O_RDONLY);
	if (fd_temp == -1)
	{
		perror("zsh");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd_temp, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(fd_temp);
	close(tube[READ_TUBE]);
	if (dup2(tube[WRITE_TUBE], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(tube[WRITE_TUBE]);
	//exec_first_command(argv, env);

	char	*path_program;
	char	*command;
	char	**arguments;
	command = ft_split(argv[2], ' ')[0];
	path_program = ft_strjoin("/bin/", command);
	arguments = ft_split(argv[2], ' ');
	//arguments = insert_element_last_pos(arguments, INFILE);
	execve(path_program, arguments, env); 
	{
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}

void	child2(char* argv[], char **env, int tube[2])
{
	int	fd_temp;


	if (dup2(tube[READ_TUBE], STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(tube[READ_TUBE]);
	fd_temp = open(OUTFILE, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_temp == -1)
		exit(EXIT_FAILURE);
	if (dup2(fd_temp, STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(fd_temp);
	close(tube[WRITE_TUBE]);

	char	*path_program;
	char	*command;
	char	**arguments;

	command = ft_split(argv[3], ' ')[0];		
	path_program = ft_strjoin("/bin/", command);
/* 	if (access(path_program, X_OK) == -1) 
		{
			write(2,"falla access", 10);
		}
 */
	arguments = ft_split(argv[3], ' ');
	//arguments = insert_element_last_pos(arguments, INFILE);
	write(2, path_program, ft_strlen(path_program));
	execve(path_program, arguments, env);
	//exec_second_command(argv, env);         //
	perror("execve failed");
	exit(EXIT_FAILURE);
}

void	args_are_ok(int argc)
{
	if (argc != 5)
	{
		write(2, "Error: wrong number of arguments.\n"
			"Structure must be:\n"
			"./pipex file1 command1 command2 file2\n", 92);
		exit (-1);
	}
}

int	main(int argc, char* argv[], char **env)
{
	pid_t	fork1;
	pid_t	fork2;
	int		tube[2];
	int		status;
	int		status2;

	args_are_ok(argc);
	if (pipe(tube) != 0)
		exit(-1);
	fork1 = fork();
	if (fork1 == -1)
		exit(-1);
	if (fork1 == 0)
		child1(argv, env, tube);
	else
	{

		fork2 = fork();
		if (fork2 == -1)
			exit(-1);
		if (fork2 == 0)
			child2(argv, env, tube);
	}

	waitpid(fork2, &status2, 0);
	waitpid(fork1, &status, 0);
	
	return (0);
}

