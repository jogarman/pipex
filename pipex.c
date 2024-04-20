/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:38:04 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/04/21 00:08:18 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h> // para leer y escribir
#include <unistd.h>
#include <string.h>

//Notas:
/* Debo de recibir el argumento como una sola cadena, luego hacer el split para dividirla
y el resultado mandarlo a execve */
// implemmentar el split de mi libreria

int	main(int arg, char* argv[])
{
	int		fd_read;
	int		fd_write;
	int		pid;
	char	*arg_execve[3];

	fd_read = open("infile", O_RDONLY);
	fd_write = open("outfile", O_WRONLY);
	pid = fork();

	arg = 0;
	arg_execve[0] = split(argv)[1];
	arg_execve[1] = split(argv)[2];
	arg_execve[2] = NULL;

	printf("%s, %s\n", argv[1], arg_execve[0]);
	printf("%s, %s\n", argv[2], arg_execve[1]);
	printf("%s, %s\n", argv[3], arg_execve[2]);

	(void)argv;
	if (fd_read < 0 || fd_write < 0 || pid < 0)
		return -1;
	if (pid == 0)
	{
		printf("proceso hijo\n");
		execve("/bin/ls", arg_execve, NULL);
	}
	else
		printf("proceso padre\n");

	return 0;
}