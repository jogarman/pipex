/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:23:18 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/04 16:16:16 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
    find command in path and executes it
	arg_number:
	2 - first command
	3 - second command
*/
char	*where_is_comm(char *command, char **env)
{
	char	*path_program;
	char	**path_arr;
	int		i;

	path_arr = path_array(env);
	command = ft_strjoin("/", command);
	i = 0;
	while (path_arr[i] != NULL)
	{
		path_program = ft_strjoin(path_arr[i], command);
		//arguments = ft_split(argv[arg_number], ' ');
		if (access(path_program, X_OK) != -1)
		{
			return (path_program);
		}
		i++;
    }
	perror("command not found in path");
	return ("error: where_is_comm");
}

/*
	returns char ** of values on PATH:
	/home/jgarcia3/bin
	/home/jgarcia3/bin
	/usr/local/sbin
	/usr/local/bin
	/usr/sbin
	/usr/bin
	/sbin
	/bin
	/usr/games
	/usr/local/games
	/snap/bin
	Null
*/
char	**path_array(char **env)
{
	int		i = 0;
	char    *path;
	char    **path_split;


	while (env[i] != NULL)
	{
		path = ft_strnstr(env[i], "PATH=/h", ft_strlen(env[i]));
		if (path != NULL)
			{
				path_split = ft_split(path, ':');
				path_split[0] += 5;
				return (path_split);
			}
		i++;
	}
	perror("**env does not contain PATH");
	exit(EXIT_FAILURE);
}

/*
	Execute the argument_number given with exevec
	int		execute(int arg_number, char *argv[], char **env)
*/
int		execute(int arg_number, char *argv[], char **env)
{
	char	*path_program;
	char	*command;
	char	**arguments;
	
	//path_arr = path_array(env);
	command = ft_split(argv[arg_number], ' ')[0];
	path_program = where_is_comm(command, env);
	command = ft_strjoin("/", command);
	arguments = ft_split(argv[arg_number], ' ');
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