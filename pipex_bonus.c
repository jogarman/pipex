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
	dprintf(2, "first_child -- IN %d --- OUT %d\n", fd_temp, tube_out[WRITE_TUBE]);
	execute_b(2, argv, env);
}
/* mid_child(argv, env, tubes_arr, i, n_command); */
/* argv[arg_number] <- para el n_command */
void	mid_child(char *argv[], char **env, int **tubes_arr, int i, int n_command)
{
	int	tube_in[2];
	int	tube_out[2];
	dprintf(2, "mid_child number %d\n", i);
	
//	tube_in[0] = tubes_arr[i -1][0];
//	tube_in[1] = tubes_arr[i -1][1];
//	tube_out[0] = tubes_arr[i][0];
//	tube_out[1] = tubes_arr[i][1];
//	ft_memcpy(tube_in, &tubes_arr[i - 1][0], sizeof(int) * 2); //
//	ft_memcpy(tube_out, &tubes_arr[i][0], sizeof(int) * 2);	   
	dprintf(2, "|---mid %s IN:%d OUT:%d----|\n", argv[n_command], tubes_arr[i -1][0], tubes_arr[i][1]);

	close(tubes_arr[i -1][1]);
	if ((dup2(tubes_arr[i -1][0], STDIN_FILENO) == -1))  // Redirecciono tubo IN
		dup2_fail(tube_in, 1, "Dup2 tube_in failed, mid child\n");
	close(tubes_arr[i -1][0]);

	close(tubes_arr[i][0]);
	if (dup2(tubes_arr[i][1], STDOUT_FILENO) == -1) // Redirecciono tubo OUT
		dup2_fail(tube_out, 1, "Dup2 tube_out failed, mid child\n");
	close(tubes_arr[i][1]);

	execute_b(n_command, argv, env);						//	SELECCIONAR ARGUMENTO 
}


void	last_child(char *argv[], char **env, int last_tube[2], int n_last_command)
{
	int	fd_temp;


	fd_temp = open(argv[n_last_command +1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_temp == -1)
	{
		perror(ft_itoa(n_last_command));
		exit(EXIT_FAILURE);
	}

	if (dup2(fd_temp, STDOUT_FILENO) == -1)
		dup2_fail(last_tube, fd_temp, "Dup2 tube_out failed, last child\n");
	close(fd_temp);			//last comand debe ser 3 cuando hay 5 argumentos. 4 cuando son 6 (3 comnds)

	close(last_tube[WRITE_TUBE]);
	if ((dup2(last_tube[READ_TUBE], STDIN_FILENO) == -1))
		dup2_fail(last_tube, 1, "Dup2 tube_in failed, last child\n");
	close(last_tube[READ_TUBE]);

	
	dprintf(2, "last_child -- IN %d --- OUT %d\n", last_tube[READ_TUBE], fd_temp);
	execute_b(n_last_command, argv, env);
}

void	close_tube_and_waitpid(int tube[2], pid_t fork1, pid_t fork2)
{
	close(tube[0]);
	close(tube[1]);
	waitpid(fork1, NULL, 0);
	waitpid(fork2, NULL, 0);
}
/* 

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
			exit(EXIT_SUCCESS);
		}
		i++;
		n_command++;
	}
	/////////
	fork1 = fork();
	if (fork1 == -1)
		exit(-1);
	if (fork1 == 0)
	{
		first_child(argv, env, tubes_arr[0]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		fork2 = fork();
		if (fork2 == -1)
			exit(-1);
		if (fork2 == 0)
		{
			last_child(argv, env, tubes_arr[n_tubes - 1], argc - 2);
			exit(EXIT_SUCCESS);
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
