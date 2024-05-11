/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:48:55 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/11 20:36:53 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define READ_TUBE	0
# define WRITE_TUBE	1

char	**path_array(char **env);
char	*where_is_comm(char *command, char **env);
int		execute(int arg_number, char *argv[], char **env);
void	args_are_ok(int argc);

#endif