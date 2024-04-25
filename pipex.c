/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:30:55 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/04/25 20:12:26 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	Takes array -arguments-, make malloc + 1. Copy every element,
	add last element and add NULL
*/

char	**insert_element_last_pos(char **arguments_input, char *last_element)
{
	int		i;
	char	**argument_ret;

	argument_ret = malloc((arraylen(arguments_input) + 2) * sizeof(char*));
	i = 0;
	while (arguments_input[i] != NULL)
	{
		argument_ret[i] = arguments_input[i];
		i++;
	}
	argument_ret[i] = last_element;
	argument_ret[++i] = NULL;
	return (argument_ret);
}

//argv[0] = nombre archivo (pipex.c)
//argv[1] = infile
//argv[2] = comando y flags

// PENDIENTE: HACER MAKEFILE PARA METER LAS FUNCIONES AUXILIARES EN UTILS
int	main(int argc, char* argv[], char **env)
{
	char	*path_program;
	char	*command;
	char	**arguments;

	(void)argc;	//eliminar
	command = ft_split(argv[2], ' ')[0];
	path_program = ft_strjoin("/bin/", command);

	arguments = ft_split(argv[2], ' ');	// Creamos la lista para pasar a execve

	//ft_print_vector(&argv[2]);			//Imprime arg2
	//ft_print_vector(arguments);			//Imprime el split de arg2

	arguments = insert_element_last_pos(arguments, argv[1]); // hacer free()?
	execve(path_program, arguments, env);
}
