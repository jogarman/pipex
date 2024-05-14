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
	{
		dup2_fail(tube_out, fd_temp, "Dup2 tube_out failed, first child\n");
	}
	close(tube_out[WRITE_TUBE]);
	dprintf(2, "first_child\n");
	execute_b(2, argv, env);
}
/* mid_child(argv, env, tubes_arr, i, n_command); */
/* argv[arg_number] <- para el n_command */
void	mid_child(char *argv[], char **env, int **tubes_arr, int i, int n_command)
{
	int	tube_in[2];
	int	tube_out[2];
	dprintf(2, "mid_child number %d\n", i);
	
	ft_memcpy(tube_in, tubes_arr[i - 1], sizeof(int) * 2); //
	ft_memcpy(tube_out, tubes_arr[i], sizeof(int) * 2);	   

	close(tube_in[WRITE_TUBE]);

	if ((dup2(tube_in[READ_TUBE], STDIN_FILENO) == -1))  // Redirecciono tubo IN
		dup2_fail(tube_in, 1, "Dup2 tube_in failed, mid child\n");
	close(tube_in[READ_TUBE]);

	close(tube_out[WRITE_TUBE]);
	if (dup2(tube_out[READ_TUBE], STDOUT_FILENO) == -1) // Redirecciono tubo OUT
		dup2_fail(tube_out, 1, "Dup2 tube_out failed, mid child\n");
	close(tube_out[READ_TUBE]);

	dprintf(2, "|---mid %s----|\n", argv[n_command]);
	execute_b(n_command, argv, env);						//	SELECCIONAR ARGUMENTO */
}


void	last_child(char *argv[], char **env, int last_tube[2], int n_last_command)
{
	int	fd_temp;

	if ((dup2(last_tube[READ_TUBE], STDIN_FILENO) == -1))
		dup2_fail(last_tube, 1, "Dup2 tube_in failed, last child\n");

	close(last_tube[WRITE_TUBE]);
	fd_temp = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_temp == -1)
	{
		perror(ft_itoa(n_last_command));
		exit(EXIT_FAILURE);
	}
	close(last_tube[READ_TUBE]);
	if (dup2(fd_temp, STDOUT_FILENO) == -1)
		dup2_fail(last_tube, fd_temp, "Dup2 tube_out failed, last child\n");
	close(fd_temp);			//last comand debe ser 3 cuando hay 5 argumentos. 4 cuando son 6 (3 comnds)
	
	dprintf(2, "last_child\n");
	execute_b(n_last_command - 1, argv, env);
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

1- ESTA FALLANDO EL EXEVEC DEL MID CHILD
3- O_APPEND >> BONUS just for here_doc >> 
instead of O_trunc */

int	main(int argc, char *argv[], char **env)
{
	pid_t	fork1;
	pid_t	fork2;
	int		n_tubes;
	int		i;
	int		**tubes_arr;
	int		id;
	int		n_command; //numero de comando en el que están los argumentos del mid_child

	args_are_ok_b(argc);
	n_tubes = get_n_tubes(argc, argv);
	tubes_arr = get_tubes_arr(n_tubes);
	n_command = get_init_pos_mid_command(argv); // 3 sin here_doc, 4 con here_doc
	i = 1;
 	while  (i < n_tubes)
	{
		id = fork();
		if (id == 0)
		{
			mid_child(argv, env, tubes_arr, i, n_command);
		}
		i++;
		n_command++;
	}
	/////////
	fork1 = fork();
	if (fork1 == -1)
		exit(-1);
	if (fork1 == 0)
		first_child(argv, env, tubes_arr[0]);
	else
	{
		fork2 = fork();
		if (fork2 == -1)
			exit(-1);
		if (fork2 == 0)
		{
			dprintf(2, "-----%d-----", n_tubes);
			last_child(argv, env, tubes_arr[n_tubes - 1], argc - 2);
		}
		if (fork2 > 0)
		{
			wait(NULL);
	/* 		close_tube_and_waitpid(first_tube, fork1, fork2);
			close_tube_and_waitpid(last_tube, fork1, fork2); */
		}
	}
	/////////////////////////////
	return (0);
}
