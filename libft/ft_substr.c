/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:41:10 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/15 18:24:45 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
//return (ft_calloc(1, 1));
other choizes as NULL, 0, '\0' or "\0" dont work
*/
/*
Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_str;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || *s == '\0')
		return (ft_calloc(1, 1));
	i = 0;
	if ((size_t)ft_strlen(s) - (size_t)start < len)
		len = (size_t)ft_strlen(s) - (size_t)start;
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (sub_str == NULL)
	{
		return (NULL);
	}
	while (s[start] != '\0' && i != len)
	{
		sub_str[i++] = s[start];
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
/*
int	main()
{
	printf(">%s<", ft_substr("hola", 0, 18446744073709551615));
}*/