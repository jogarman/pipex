/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:38:04 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/04/23 17:37:31 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//argv[0] = nombre archivo (pipex.c)
//argv[1] = infile
//argv[2] = comando

int	main(int argc, char* argv[], char **env)
{
	(void)argc;
	pid_t	pid;		//forks
	pid_t	fd_pipe[2]; //pipe
	//pid_t	fd_read;	//read
	char	**command_1;
	int	outfd

	command_1 = ft_split(argv[2], ' ');

	close(1);

	pid = fork();
	if (pid == 0)	//ft_printf("proceso hijo\n");
	{
 		char *args_execve[] = {"cat", "infile", NULL};
		execve("/bin/cat", args_execve, env);
	}
	else
	{
		pipe(fd_pipe);
		= open("outfile", O_WRONLY);
		fd_pipe[0] = open("infile", O_RDONLY);
		ft_printf("%d\n", pid);
		char *args_execve[] = {"cat", "infile", NULL};
		execve("/bin/cat", args_execve, env);
	}
	return 0;
}