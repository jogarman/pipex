/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:38:04 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/04/23 19:45:13 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//argv[0] = nombre archivo (pipex.c)
//argv[1] = infile
//argv[2] = comando
int	main(int argc, char* argv[], char **env)
{
	(void)argc;
	char	**command_1;
	pid_t	pid1;
	command_1 = ft_split(argv[2], ' ');
	int fd[2];
	int status; // variable para ver el estado de los hijos

	pipe(fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		close(fd[])
	}



/* 	int fd_infile = open("infile", O_RDONLY);
	close(1);
	int fd_outfile = open("outfile", O_WRONLY);

	pid1 = fork();
	if (pid1 == 0)		// Proceso hijo 1
	{
		write(2, "hijo1", 5);
 		char *args_execve1[] = {"cat", "infile", NULL};
		execve("/bin/cat", args_execve1, env);
	}
	return 0; */
}

/* 	int new_fd = open("/dev/tty", O_WRONLY);  //abrir el fd1 otra vez
	dup2(new_fd, 1); */