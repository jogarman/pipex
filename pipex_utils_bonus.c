/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:41:58 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/12 20:03:16 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int		get_n_tubes(int argc, char *argv[])
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		return (argc - 5); 
	return (argc - 4);
}

/* int 	main(int argc, char *argv[])
{
    printf("%d", get_n_tubes(argc, argv));
} */