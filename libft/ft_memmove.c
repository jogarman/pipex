/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:41:06 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/04 19:52:23 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	move(unsigned char *d, const unsigned char *s, size_t len)
{
	size_t	i;

	i = 0;
	if (d <= s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*d;
	unsigned const char		*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	move(d, s, len);
	return (dst);
}

/*
#include<string.h>
int	main()
{
    const char source[] = "Hello, World!";
    size_t length = 5;
    char destination[20];

    const char source_o[] = "Hello, World!";
    size_t length_o = 5;
    char destination_o[20];
    printf("%s\n", ft_memmove(destination, source, length));
    printf("%s\n", memmove(destination_o, source_o, length_o));
    // Imprimir el resultado
    printf("Cadena de origen_ft: %s\n", source);
    printf("Cadena de destino_ft: %s\n", destination);

    printf("Cadena de origen_o: %s\n", source_o);
    printf("Cadena de destino_o: %s\n", destination_o);
    return 0;
}*/