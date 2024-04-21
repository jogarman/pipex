/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:17:08 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/13 18:39:39 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	char				*ret_dst;
	unsigned char		*dst_char;
	unsigned const char	*src_char;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_char = (unsigned char *)dst;
	src_char = (unsigned const char *)src;
	ret_dst = (char *)dst;
	i = 0;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	return (ret_dst);
}

/*
#include <unistd.h>
#include <string.h>
int	main()
{
    char destination[20] = "\0abc";
    char destination2[20] = "\0abc";

	memcpy(NULL, NULL, 1);
	printf("destino: %s\n", destination2);
    ft_memcpy(NULL, NULL, 1);
    printf("destino: %s\n", destination);

    return 0;
}
*/