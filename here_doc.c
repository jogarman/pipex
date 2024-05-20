/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:23:40 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/20 15:37:26 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	open_temp(char *action)
{
	int		fd_open;

	if (strncmp("create", action, ft_strlen(action)) == 0)
		fd_open = open("temp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_open == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd_open);
}

static void	loop_write_to_temp(char *eof, int fd_temp)
{
	int		bytes_read;
	char	buffer[1024];

	while (1)
	{
		write(1, "> ", 2);
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
		if (bytes_read <= 0)
		{
			perror("read");
			free(eof);
			exit(EXIT_FAILURE);
		}
		buffer[bytes_read] = '\0';
		if (buffer[bytes_read - 1] == '\n')
		{
			buffer[bytes_read - 1] = '\0';
			bytes_read--;
		}
		if (strncmp(eof, buffer, ft_strlen(buffer)) == 0)
			return ;
		write(fd_temp, buffer, bytes_read);
		write(fd_temp, "\n", 1);
	}
}

/* returns fd of a temporary file with data to open by first child */
void	here_doc(char *argv[])
{
	char	*eof;
	int		fd_temp;

	eof = ft_strdup(argv[2]);
	fd_temp = open_temp("create");
	loop_write_to_temp(eof, fd_temp);
	close(fd_temp);
}
