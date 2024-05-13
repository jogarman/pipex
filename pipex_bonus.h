/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:48:55 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/13 19:25:42 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <fcntl.h> // para leer y escribir
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
int     get_n_tubes(int argc, char *argv[]);
int		**get_tubes_arr(int n_tubes);
int		get_init_pos_mid_command(char *argv[]);
void	dup2_fail(int tube[2], int fd_temp, char *fail_comment);

#endif