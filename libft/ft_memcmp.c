/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:42:25 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/13 18:39:28 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  n should be equal or shorter than s1 and s2. If notr, result may be undefined
 */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && st1[i] == st2[i])
	{
		i++;
	}
	return (st1[i] - st2[i]);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char cad1[] = "a";
	char cad2[] = "a";
	size_t	n = 1;

	printf("%d\n", ft_memcmp(cad1, cad2, n));
	printf("%d", memcmp(cad1, cad2, n));
}*/
