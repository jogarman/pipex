/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_fork_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:58:12 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/20 15:46:14 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	last_child(char *argv[], char **env, int last_tube[2], int n_last_comm)
{
	int	fd_temp;

	close(last_tube[WRITE_TUBE]);
	if ((dup2(last_tube[READ_TUBE], STDIN_FILENO) == -1))
		dup2_fail(last_tube, 1, "Dup2 tube_in failed, last child\n");
	close(last_tube[READ_TUBE]);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		fd_temp = open(argv[n_last_comm + 1], O_CREAT | O_WRONLY | O_APPEND, \
		0644);
	else
		fd_temp = open(argv[n_last_comm + 1], O_CREAT | O_WRONLY | O_TRUNC, \
		0644);
	if (fd_temp == -1)
	{
		perror("last_child");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd_temp, STDOUT_FILENO) == -1)
		dup2_fail(last_tube, fd_temp, "Dup2 tube_out failed, last child\n");
	close(fd_temp);
	execute_b(n_last_comm, argv, env);
}

void	last_fork(char *argv[], char **env, t_pipex s_pipex, int argc)
{
	pid_t	fork2;

	fork2 = fork();
	if (fork2 == -1)
		exit(-1);
	if (fork2 == 0)
	{
		last_child(argv, env, s_pipex.tubes_arr[s_pipex.n_tubes - 1], argc - 2);
		exit(EXIT_SUCCESS);
	}
	if (fork2 > 0)
	{
		wait(NULL);
		unlink("temp");
		free_and_close_array(s_pipex.tubes_arr);
	}
}
