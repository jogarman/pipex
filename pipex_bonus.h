/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:48:55 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/20 15:17:04 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define READ_TUBE	0
# define WRITE_TUBE	1

typedef struct t_pipex
{
	int	**tubes_arr;
	int	i;
	int	n_tubes;
	int	id;
	int	n_command;
}	t_pipex;

void	args_are_ok(int argc);
void	dup2_fail(int tube[2], int fd_temp, char *fail_comment);

/************ Bonus *************/
char	**path_array_b(char **env);
char	*where_is_comm_b(char *command, char **env);
int		execute_b(int arg_number, char *argv[], char **env);

void	args_are_ok_b(int argc);
int		get_n_tubes(int argc, char *argv[]);
int		**get_tubes_arr(int n_tubes);
int		get_init_pos_mid_command(char *argv[]);
void	free_and_close_array(int **array);

/********* Forks & childs ********/
void	first_fork(char *argv[], char **env, t_pipex s_pipex);
void	mid_fork_loop_caller(char *argv[], char **env, t_pipex s_pipex);
void	last_fork(char *argv[], char **env, t_pipex s_pipex, int argc);

/*********** Here_doc ************/
void	here_doc(char *argv[]);

#endif