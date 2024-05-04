/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jft_print_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:36:25 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/04 23:48:21 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf/ft_printf.h"

/*
	prints an array of arrays.
	returns number of strings printed
	"%d>%s<
*/
int	jft_print_vector(char **vector)
{
	int		i;

	i = 0;
	while (vector[i] != NULL)
		i++;
	ft_printf("%d>Null\n", i);
	return (i);
}

/* int  main()
{
	char	*arr[] = {"hola", "mundo", NULL};
	jft_print_vector(arr);
} */