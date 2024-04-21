/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:38:04 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/04/21 22:30:05 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Notas:
/* Debo de recibir el argumento como una sola cadena, luego hacer el split para dividirla
y el resultado mandarlo a execve */
// implementar el split de mi libreria

int	main(int arg, char* argv[])
{
	int		fd_read;
	int		fd_write;
	int		pid;
	char	*arg_execve[3];

	fd_read = open("infile", O_RDONLY);
	fd_write = open("outfile", O_WRONLY);
	pid = fork();

	(void)argv;
	arg = 0;
	if (fd_read < 0 || fd_write < 0 || pid < 0)
		return -1;
	if (pid == 0)
	{
		//ft_printf("proceso hijo\n");
		execve("/bin/ls", arg_execve, NULL);
	}
	else
		//ft_printf("proceso padre\n");
		ft_printf("%d", ft_isdigit(43));
	return 0;
}