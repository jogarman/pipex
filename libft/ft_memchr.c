/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:37:18 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/13 18:38:53 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (n != i)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

/*

int	main()
{
	//char	s[] = "aaa";
	//int		caracter = '';
	//size_t	n = 20;
	int tab[7] = {49, -49, 1, -1, 0, -2, 2};

	printf("%s\n", memchr(tab, -49, 7));
	printf("%s\n", ft_memchr(tab, -49, 7));
	printf("%s\n", memchr("bonjour", 'j', 6));
	printf("%s", ft_memchr("bonjour", 'j', 6));
}*/