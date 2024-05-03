/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:36:32 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/03 20:14:12 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

/*
returns char ** of values on PATH:
/home/jgarcia3/bin
/home/jgarcia3/bin
/usr/local/sbin
/usr/local/bin
/usr/sbin
/usr/bin
/sbin
/bin
/usr/games
/usr/local/games
/snap/bin
Null
*/
char	**path_array(char **env)
{
	int		i = 0;
	char    *path;
	char    **path_split;


	while (env[i] != NULL)
	{
		path = ft_strnstr(env[i], "PATH=/h", ft_strlen(env[i]));
		if (path != NULL)
			{
				path_split = ft_split(path, ':');
				path_split[0] += 5;
				return (path_split);
			}
		i++;
	}
	perror("**env does not contain PATH");
	exit(EXIT_FAILURE);
}

/*  
int		main(int argc, char* argv[], char **env)
{
    (void)	argc;
    (void)	argv;
	char	**string = find_path(env);
	int		i = 0;

	printf("empieza PATH:\n");
	while (string[i] != NULL)
	{
		printf("%d>%s<\n",i, string[i]);
		i++;
	}
	if (string[i] == NULL)
	{
		printf("%d>Null\n", i);
	}
} */