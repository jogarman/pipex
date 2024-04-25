/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:43:20 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/04/25 19:49:50 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
	returns lenght of an array of arrays
*/
int		arraylen(char **array)
{
	int i;

	i = 0;
	while(array[i] != NULL)
		i++;
	return (i);
}