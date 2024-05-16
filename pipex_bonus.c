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
	if (dup2(tube_out[WRITE_TUBE], STDOUT_FILENO) == -1)
		dup2_fail(tube_out, fd_temp, "Dup2 tube_out failed, first child\n");
	close(fd_temp);
	close(tube_out[READ_TUBE]);
	close(tube_out[WRITE_TUBE]);
	execute_b(2, argv, env);
}

/* mid_child(argv, env, tubes_arr, i, n_command); */
/* argv[arg_number] <- para el n_command */
void	mid_child(char *argv[], char **env, int **tubes_arr, int i, int n_command)
{
	close(tubes_arr[i - 1][WRITE_TUBE]);
	if ((dup2(tubes_arr[i - 1][0], STDIN_FILENO) == -1))
		dup2_fail(tubes_arr[i - 1], 1, "Dup2 tube_in failed, mid child\n");

	if (dup2(tubes_arr[i][1], STDOUT_FILENO) == -1)
		dup2_fail(tubes_arr[i], 1, "Dup2 tube_out failed, mid child\n");
	
	close(tubes_arr[i-1][0]);
	close(tubes_arr[i-1][1]);
	close(tubes_arr[i][0]);
	close(tubes_arr[i][1]);

	execute_b(n_command, argv, env);
}

void	last_child(char *argv[], char **env, int last_tube[2], int n_last_command)
{
	int	fd_temp;

	close(last_tube[WRITE_TUBE]);
	if ((dup2(last_tube[READ_TUBE], STDIN_FILENO) == -1))
		dup2_fail(last_tube, 1, "Dup2 tube_in failed, last child\n");
	close(last_tube[READ_TUBE]);

	fd_temp = open(argv[n_last_command + 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_temp == -1)
	{
		perror(ft_itoa(n_last_command));
		exit(EXIT_FAILURE);
	}
	if (dup2(fd_temp, STDOUT_FILENO) == -1)
		dup2_fail(last_tube, fd_temp, "Dup2 tube_out failed, last child\n");
	close(fd_temp);
	execute_b(n_last_command, argv, env);
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
	int		n_command;
	
	args_are_ok_b(argc);
	n_tubes = get_n_tubes(argc, argv);
	tubes_arr = get_tubes_arr(n_tubes);
	n_command = get_init_pos_mid_command(argv); // 3 sin here_doc, 4 con here_doc
	
	// close(tubes_arr[0][0]);
	// close(tubes_arr[0][0]);
	fork1 = fork();
	if (fork1 == -1)
		exit(-1);
	if (fork1 == 0)
	{
		first_child(argv, env, tubes_arr[0]);
		exit(EXIT_SUCCESS);
	}
	
	///////////////MIDDLE////////////
	i = 1;
 	while  (i < n_tubes)
	{
		close(tubes_arr[i - 1][WRITE_TUBE]);
		id = fork(); // Se debe proteger el fork. Si es -1 exit()
		if (id == 0)
		{
			mid_child(argv, env, tubes_arr, i, n_command);
			exit(EXIT_SUCCESS);  //Funciona sin él?
		}
		//close(tubes_arr[i-1][READ_TUBE]);
		//close(tubes_arr[i][1]);
		i++;
		n_command++;
	}
	close(tubes_arr[i - 1][WRITE_TUBE]);
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
		free_and_close_array(tubes_arr);
	}
	return (0);
}
