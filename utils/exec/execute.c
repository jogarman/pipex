/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:23:18 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/03 20:19:32 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

/*
	Execute the argument_number given with exevec
	int		execute(int arg_number, char *argv[], char **env)
*/
int		execute(int arg_number, char *argv[], char **env)
{
	char	*path_program;
	char	*command;
	char	**arguments;
	char	**path_arr;

	path_arr = path_array(env);
	command = ft_split(argv[arg_number], ' ')[0];
	path_program = where_is_comm(command, env);
	command = ft_strjoin("/", command);
	arguments = ft_split(argv[2], ' ');
	execve(path_program, arguments, env);
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
}

/* 
int	main(int argc, char* argv[], char **env)
{
	execute(2,  argv, env);
}
*/