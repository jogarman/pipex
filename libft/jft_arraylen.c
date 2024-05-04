/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jft_arraylen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:43:20 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/04 23:48:28 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	returns lenght of an array of arrays
*/
int	jft_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}
