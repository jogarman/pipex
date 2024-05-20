/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:47:49 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/20 16:03:23 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* Number of arguments must be 4 according subject */
void	args_are_ok(int argc)
{
	if (argc != 5)
	{
		perror("Error: wrong number of arguments.\n"
			"Structure must be:\n"
			"./pipex infile command1 command2 outfile");
		exit (-1);
	}
}

int	main(int argc, char *argv[], char **env)
{
	t_pipex	s_pipex;

	args_are_ok(argc);
	s_pipex.n_tubes = get_n_tubes(argc, argv);
	s_pipex.tubes_arr = get_tubes_arr(s_pipex.n_tubes);
	s_pipex.n_command = get_init_pos_mid_command(argv);
	first_fork(argv, env, s_pipex);
	mid_fork_loop_caller(argv, env, s_pipex);
	last_fork(argv, env, s_pipex, argc);
	return (0);
}
