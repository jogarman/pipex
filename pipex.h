/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:48:55 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/04 23:53:05 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ_TUBE	0
# define WRITE_TUBE	1
# define INFILE		argv[1] //cambiar esto
# define COMMAND_1  argv[2] //a norminette no le gusta:
# define COMMAND_2  argv[3] //Preprocessor statement must only contain 
                            //constant defines
# define OUTFILE	argv[4]

#endif

#include <stdio.h>
#include <fcntl.h> // para leer y escribir
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "libft/libft.h"
//# include "libft/ft_printf/ft_printf.h"
//# include "libft/get_next_line/get_next_line.h"

char	**path_array(char **env);
char	*where_is_comm(char *command, char **env);
int		execute(int arg_number, char *argv[], char **env);
/* 
int     args_are_ok(int argc);
void	child2(char* argv[], char **env, int tube[2]);
void	child1(char* argv[], char **env, int tube[2]);
void	exec_first_command(char* argv[], char **env);
char	**insert_element_last_pos(char **arguments_input, char *last_element);
void	exec_second_command(char* argv[], char **env); */

