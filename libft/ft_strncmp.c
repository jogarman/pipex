/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:25:33 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/04 23:48:12 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strnstr() function locates the first occurrence of the  
null-terminated  string little in the string big, where not more
than len characters are searched. Characters that appear after	a `\0'
character are not  searched.

---> strnstr(const char *haystack, const char *needle, size_t len);
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;

	s1_temp = (unsigned char *)(s1);
	s2_temp = (unsigned char *)(s2);
	i = 0;
	if (n == 0)
		return (0);
	while
	(
	i < (n - 1)
	&& s1_temp[i] != '\0'
	&& s2_temp[i] != '\0'
	&& s1_temp[i] == s2_temp[i]
	)
	i++;
	return (s1_temp[i] - s2_temp[i]);
}

/*
#include <stdio.h>
#include <string.h>
int	main()
{
	printf("o__->  %d\n", strncmp( "ol","hola mundo cruel", 2));
	printf("ft_->  %d", ft_strncmp("ol","hola mundo cruel", 10));
	return (0);
} */
