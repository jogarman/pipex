/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:30:55 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/11 20:59:56 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

/*
	Close FDs ands exit program printing given error
*/
void	dup2_fail(int tube[2], int fd_temp, char *fail_comment)
{
	close(tube[WRITE_TUBE]);
	close(fd_temp);
	ft_putstr_fd(fail_comment, 2);
	exit(EXIT_FAILURE);
}

void	first_child(char *argv[], char **env, int tube_out[2])
{
	int	fd_temp;

	fd_temp = open(argv[1], O_RDONLY);
	if (fd_temp == -1)
	{
		perror("zsh");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd_temp, STDIN_FILENO) == -1)
		dup2_fail(tube_out, fd_temp, "Dup2 tube_in failed, first child\n");
	close(fd_temp);
	close(tube_out[READ_TUBE]);
	if (dup2(tube_out[WRITE_TUBE], STDOUT_FILENO) == -1)
		dup2_fail(tube_out, fd_temp, "Dup2 tube_out failed, first child\n");
	close(tube_out[WRITE_TUBE]);
	execute(2, argv, env);
}

void	mid_child(char *argv[], char **env, int tube_in[2], int tube_out[2], int n_command)
{
	close(tube_in[WRITE_TUBE]);
	if ((dup2(tube_in[READ_TUBE], STDIN_FILENO) == -1)) 		   // Redirecciono tubo IN
		dup2_fail(tube_in, 1, "Dup2 tube_in failed, mid child\n");
	close(tube_in[READ_TUBE]);

	close(tube_out[READ_TUBE]);
	if (dup2(tube_out[WRITE_TUBE], STDOUT_FILENO) == -1) // Redirecciono tubo OUT
		dup2_fail(tube_out, 1, "Dup2 tube_out failed, mid child\n");
	close(tube_out[WRITE_TUBE]);
	execute(n_command, argv, env);						//	SELECCIONAR ARGUMENTO */
}


void	last_child(char *argv[], char **env, int last_tube[2], int n_last_command)
{
	int	fd_temp;

if ((dup2(last_tube[READ_TUBE], STDIN_FILENO) == -1))
		dup2_fail(last_tube, 1, "Dup2 tube_in failed, last child\n");
	close(last_tube[READ_TUBE]);
	fd_temp = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_temp == -1)
	{
		perror(argv[4]);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd_temp, STDOUT_FILENO) == -1)
		dup2_fail(last_tube, fd_temp, "Dup2 tube_out failed, last child\n");
	close(last_tube[WRITE_TUBE]);
	close(fd_temp);			//last comand debe ser 3 cuando hay 5 argumentos. 4 cuando son 6 (3 comnds)

	execute(n_last_command, argv, env);
}

void	close_tube_and_waitpid(int tube[2], pid_t fork1, pid_t fork2)
{
	close(tube[0]);
	close(tube[1]);
	waitpid(fork1, NULL, 0);
	waitpid(fork2, NULL, 0);
}
/* 
DE MOMENTO SOLO FALLA EL MID_CHILD EN ALGUN PUNTO

1- comprobar que mid_child funciona //Antes debemos hacer que el bucle de forks  funcione
2 - DEBEMOS CREAR EL NUMERO DE PIPES QUE VAMOSS A NECESITAR ANTES DE HACER EL PRIMER FORK
PORQUE LUEGO SE VAN A DUPLICAR
3- O_APPEND >> BONUS just for here_doc >> 
instead of O_trunc */

int	main(int argc, char *argv[], char **env)
{
	pid_t	fork1;
	pid_t	fork2;
	pid_t	fork_mid;
	int		tube1[2];
	int		tube2[2];
	int		n_tubes;
	int		i;
	int		**tubes_arr;
	int		id;

	args_are_ok(argc);
	n_tubes = get_n_tubes(argc, argv);
	tubes_arr = ft_calloc((size_t)n_tubes + 1, (size_t)sizeof(int *));
	i = 0;
	while (i != n_tubes)
	{
		tubes_arr[i] = ft_calloc(2 + 1, (size_t)sizeof(int));
		i++;
	}
/////////////////////
	if (pipe(tube1) != 0)
		exit(-1);
	if (pipe(tube2) != 0)
		exit(-1);
	/////////
	i = 1;
 	while  (i < n_tubes)
	{
		printf("%i", i);
		id = fork();
		if (id != 0)
		{
			write(2, "mid child: ", 10);
			char *s = ft_itoa(i);
			write(2, s, 10);
			mid_child(argv, env, tubes_arr[i - 1], tubes_arr[i], 3);
		}
		i++;
	}
	/////////
	fork1 = fork();
	if (fork1 == -1)
		exit(-1);
	if (fork1 == 0)
		first_child(argv, env, tube1);
	else
	{
		fork2 = fork();
		if (fork2 == -1)
			exit(-1);
		if (fork2 == 0)
			last_child(argv, env, tube2, 4);
		if (fork2 > 0)
		{
			close_tube_and_waitpid(tube1, fork1, fork2);
			close_tube_and_waitpid(tube2, fork1, fork2);
		}
	}
	/////////////////////////////
	return (0);
}
