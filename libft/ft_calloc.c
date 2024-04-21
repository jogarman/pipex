/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:08:33 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/13 19:10:57 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*pointer;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	pointer = malloc(size * count);
	i = 0;
	if (pointer == 0)
		return (NULL);
	while (i < count * size)
	{
		pointer[i] = 0;
		i++;
	}
	return ((void *)pointer);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int	main()
{
	int	size = 3;
	int	count = 2;

	//array_ft = (int *)ft_calloc(size, count);
    printf("Valores iniciales del array FT:\n");
    write(1, ft_calloc(size, count), size * count);
	write(1, "\n", 1);

	//array_original = (int *)calloc(size, count);
    printf("Valores iniciales del array original:\n");
    write(1, calloc(size, count), size * count);
	write(1, "\n", 1);

    return 0; // Terminar el programa con éxito
}*/
