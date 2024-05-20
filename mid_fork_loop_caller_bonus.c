/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_fork_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:16:45 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/20 15:23:55 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* mid_child(argv, env, tubes_arr, i, n_command); */
/* argv[arg_number] <- para el n_command */
void	mid_child(char *argv[], char **env, t_pipex s_pipex)
{
	close(s_pipex.tubes_arr[s_pipex.i - 1][WRITE_TUBE]);
	if ((dup2(s_pipex.tubes_arr[s_pipex.i - 1][0], STDIN_FILENO) == -1))
	{
		dup2_fail(s_pipex.tubes_arr[s_pipex.i - 1], 1, "Dup2 tube_in failed,\
		mid child\n");
	}
	if (dup2(s_pipex.tubes_arr[s_pipex.i][1], STDOUT_FILENO) == -1)
	{
		dup2_fail(s_pipex.tubes_arr[s_pipex.i], 1, "Dup2 tube_out failed, \
		mid child\n");
	}
	close(s_pipex.tubes_arr[s_pipex.i - 1][0]);
	close(s_pipex.tubes_arr[s_pipex.i - 1][1]);
	close(s_pipex.tubes_arr[s_pipex.i][0]);
	close(s_pipex.tubes_arr[s_pipex.i][1]);
	execute_b(s_pipex.n_command, argv, env);
}

void	mid_fork_loop_caller(char *argv[], char **env, t_pipex s_pipex)
{
	s_pipex.i = 1;
	while (s_pipex.i < s_pipex.n_tubes)
	{
		close(s_pipex.tubes_arr[s_pipex.i - 1][WRITE_TUBE]);
		s_pipex.id = fork();
		if (s_pipex.id == -1)
			exit(-1);
		if (s_pipex.id == 0)
		{
			mid_child(argv, env, s_pipex);
			exit(EXIT_SUCCESS);
		}
		s_pipex.i++;
		s_pipex.n_command++;
	}
	close(s_pipex.tubes_arr[s_pipex.i - 1][WRITE_TUBE]);
}
