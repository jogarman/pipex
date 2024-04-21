/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:38:04 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/04/22 00:32:14 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Notas:

/*
1-Para que puñetas es infile????
2- añadirr el segundo argumento con el pipe para termminar de comprender como funciona
3- añadir todos llos  comandos
*/

//argv[1] = infile
//argv[2] = comando

int	main(int arg, char* argv[])
{
	int		fd_read;
	int		fd_write;
	int		pid = 0;
	char	*arg_execve[3];
	char	*comando;
	char	**execve_args;


	execve_args = ft_split(argv[2], ' ');
	ft_printf("%s\n", execve_args[0]);
	ft_printf("%s\n", execve_args[1]);

	//ft_printf("%s\n", args[1]);

/* 	fd_read = open("infile", O_RDONLY);
	fd_write = open("outfile", O_WRONLY);
	pid = fork(); */

/* 	if (fd_read < 0 || fd_write < 0 || pid < 0)
		return -1; */
	if (pid == 0)
	{

		//ft_printf("proceso hijo\n");
		execve("/bin/ls", execve_args, NULL);
	}
	else
		//ft_printf("proceso padre\n");
		ft_printf("%d", ft_isdigit(43));
	return 0;
}