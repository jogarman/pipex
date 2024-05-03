/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_is_comm_todelete.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:36:10 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/03 20:13:53 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
    find command in path and executes it
	arg_number:
	2 - first command
	3 - second command
*/

char	*where_is_comm_todelete(int arg_number, char *argv[], char **env)
{
	char	*path_program;
	char	*command;
	char	**arguments;
	char	**path_arr;
	int		i;

	path_arr = path_array(env);
	i = 0;
	while (path_arr[i] != NULL)
	{
		command = ft_split(argv[arg_number], ' ')[0];
		command = ft_strjoin("/", command);
		path_program = ft_strjoin(path_arr[i], command);
		//arguments = ft_split(argv[arg_number], ' ');
		if (access(path_program, X_OK) != -1)
			return (path_program);
		i++;
    }
	perror("command not found in path");
}
/* 		execve(path_program, arguments, env);
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
        } */
/* int	main(int argc, char* argv[], char **env)
{
	printf("--%s", where_argument_is_contained(2, argv, env));
} */