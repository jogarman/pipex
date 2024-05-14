/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:41:58 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/14 11:24:03 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int		get_n_tubes(int argc, char *argv[])
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		return (argc - 5); 
	return (argc - 4);
}

int		**get_tubes_arr(int n_tubes)
{
	int	**tubes_arr;
	int i;
	
	tubes_arr = ft_calloc((size_t)n_tubes + 1, (size_t)sizeof(int *));
	i = 0;
	while (i != n_tubes) //para 3 comandos:
						 // alloca 2 bytes para dos tubes
						 //	genera los 2 pipes para los 2 tubes		
	{
		tubes_arr[i] = ft_calloc(2, sizeof(int));
		if (pipe(tubes_arr[i]) != 0)
			exit(EXIT_FAILURE);
		i++;
	}
	return (tubes_arr);
}

/* Return the position of first mid argument, 3 if no here_doc, 4 if here_doc */
int		get_init_pos_mid_command(char *argv[])
{
	int	init_pos_mid_command;
	
	init_pos_mid_command = 3;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		init_pos_mid_command = 4;
	return (init_pos_mid_command);
}

/* Close FDs ands exit program printing given error*/
void	dup2_fail(int tube[2], int fd_temp, char *fail_comment)
{
	close(tube[WRITE_TUBE]);
	close(fd_temp);
	ft_putstr_fd(fail_comment, 2);
	exit(EXIT_FAILURE);
}

/* int 	main(int argc, char *argv[])
{
    printf("%d", get_n_tubes(argc, argv));
} */