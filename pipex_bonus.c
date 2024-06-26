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

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char **env)
{
	t_pipex	s_pipex;

	args_are_ok_b(argc);
	s_pipex.n_tubes = get_n_tubes(argc, argv);
	s_pipex.tubes_arr = get_tubes_arr(s_pipex.n_tubes);
	s_pipex.n_command = get_init_pos_mid_command(argv);
	first_fork(argv, env, s_pipex);
	mid_fork_loop_caller(argv, env, s_pipex);
	last_fork(argv, env, s_pipex, argc);
	return (0);
}
