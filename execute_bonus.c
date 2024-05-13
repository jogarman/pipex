/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:23:18 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/13 19:12:09 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

/* 
Check if number of arguments is ok
*/
void	args_are_ok(int argc)
{
	if (argc < 5)
	{
		perror("Error: wrong number of arguments.\n"
			"Structure must be:\n"
			"./pipex infile [2 or more commands] outfile");
		exit (-1);
	}
}

/*
	returns -> char ** of values on PATH:
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
	int		i;
	char	*path;
	char	**path_split;

	i = 0;
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
	ft_putstr_fd("No such file or directory\n", 2);
	exit(EXIT_FAILURE);
}

/*
    Find command in path and executes it
	arg_number:
	2 - first command
	3 - second command
*/
char	*where_is_comm(char *command, char **env)
{
	char	*path_program;
	char	**path_arr;
	int		i;

	if (access(command, X_OK) == 0)
	{
		return (command);
	}
	else
	{
		path_arr = path_array(env);
		command = ft_strjoin("/", command);
		i = 0;
		while (path_arr[i] != NULL)
		{
			path_program = ft_strjoin(path_arr[i], command);
			if (access(path_program, X_OK) != -1)
			{
				return (path_program);
			}
			i++;
		}
		write(2, &command, strlen(command));
		perror(command);
		exit(EXIT_FAILURE);
	}
}

int	jft_print_vector(char **vector)
{
	int		i;

	i = 0;
	while (vector[i] != NULL)
	{
		write(2, ft_strjoin(vector[i], "\n"), ft_strlen(vector[i]) + 1);
		i++;
	}
	return (i);
}

/*
	Execute the argument_number given with exevec
	int		execute(int arg_number, char *argv[], char **env)
*/
int	execute(int arg_number, char *argv[], char **env)
{
	char	*path_program;
	char	*command;
	char	**arguments;

	command = ft_split(argv[arg_number], ' ')[0];
	path_program = where_is_comm(command, env);
	command = ft_strjoin("/", command);
	arguments = ft_split(argv[arg_number], ' ');
	///////// MUESTRA LOS ARGUMENTOS QUE INTRODUCE EN LA FUNCION ////////////
	write(2, "-------\n", 8);
	write(2, "Numero de arg: ", 15);
	write(2, ft_itoa(arg_number), ft_strlen(ft_itoa(arg_number)));
	write(2, "\n", 1);
	write(2, ft_strjoin(argv[arg_number], "\n"), ft_strlen(argv[arg_number]) + 1);
	write(2, "-------\n", 8);

	execve(path_program, arguments, env);
	free(command);
	free(path_program);
	free(arguments);
	perror(ft_strjoin("error in execve -> ", argv[arg_number])); //leak?
	exit(EXIT_FAILURE);
	
}

/* 
int	main(int argc, char* argv[], char **env)
{
	execute(2,  argv, env);
}
*/