/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_fork_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:56:15 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/20 15:46:09 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_child(char *argv[], char **env, int tube_out[2])
{
	int	fd_temp;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		here_doc(argv);
		fd_temp = open("temp", O_RDONLY);
	}
	else
		fd_temp = open(argv[1], O_RDONLY);
	if (fd_temp == -1)
	{
		perror("open failed");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd_temp, STDIN_FILENO) == -1)
		dup2_fail(tube_out, fd_temp, "Dup2 tube_in failed, first child\n");
	if (dup2(tube_out[WRITE_TUBE], STDOUT_FILENO) == -1)
		dup2_fail(tube_out, fd_temp, "Dup2 tube_out failed, first child\n");
	close(fd_temp);
	close(tube_out[READ_TUBE]);
	close(tube_out[WRITE_TUBE]);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		execute_b(3, argv, env);
	else
		execute_b(2, argv, env);
}

void	first_fork(char *argv[], char **env, t_pipex s_pipex)
{
	pid_t	fork1;

	fork1 = fork();
	if (fork1 == -1)
		exit(-1);
	if (fork1 == 0)
	{
		first_child(argv, env, s_pipex.tubes_arr[0]);
		exit(EXIT_SUCCESS);
	}
}
