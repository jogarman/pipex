/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:30:55 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/11 20:31:57 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	Close FDs ands exit program printing given error
*/
void	dup2_fail(int tube[2], int fd_temp, char *fail_comment)
{
	close(tube[WRITE_TUBE]);
	close(fd_temp);
	ft_putstr_fd(fail_comment, 2);
	exit(EXIT_FAILURE);
}

void	child1(char *argv[], char **env, int tube[2])
{
	int	fd_temp;

	fd_temp = open(argv[1], O_RDONLY);
	if (fd_temp == -1)
	{
		perror("zsh");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd_temp, STDIN_FILENO) == -1)
		dup2_fail(tube, fd_temp, "Dup2 failed\n");
	close(fd_temp);
	close(tube[READ_TUBE]);
	if (dup2(tube[WRITE_TUBE], STDOUT_FILENO) == -1)
		dup2_fail(tube, fd_temp, "Dup2 failed\n");
	close(tube[WRITE_TUBE]);
	execute(2, argv, env);
}

/*
O_APPEND >> BONUS just for here_doc >> 
instead of O_trunc 
*/
void	child2(char *argv[], char **env, int tube[2])
{
	int	fd_temp;

	if ((dup2(tube[READ_TUBE], STDIN_FILENO) == -1))
		dup2_fail(tube, 1, "Dup2 failed\n");
	close(tube[READ_TUBE]);
	fd_temp = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_temp == -1)
	{
		perror(argv[4]);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd_temp, STDOUT_FILENO) == -1)
		dup2_fail(tube, fd_temp, "Dup2 failed\n");
	close(tube[WRITE_TUBE]);
	close(fd_temp);
	execute(3, argv, env);
}

void	close_tube_and_waitpid(int tube[2], pid_t fork1, pid_t fork2)
{
	close(tube[0]);
	close(tube[1]);
	waitpid(fork1, NULL, 0);
	waitpid(fork2, NULL, 0);
}

int	main(int argc, char *argv[], char **env)
{
	pid_t	fork1;
	pid_t	fork2;
	int		tube[2];

	args_are_ok(argc);
	if (pipe(tube) != 0)
		exit(-1);
	fork1 = fork();
	if (fork1 == -1)
		exit(-1);
	if (fork1 == 0)
		child1(argv, env, tube);
	else
	{
		fork2 = fork();
		if (fork2 == -1)
			exit(-1);
		if (fork2 == 0)
			child2(argv, env, tube);
		else if (fork2 > 0)
			close_tube_and_waitpid(tube, fork1, fork2);
	}
	return (0);
}
