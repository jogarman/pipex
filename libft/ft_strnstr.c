/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:13:04 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/15 19:56:33 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	 The strnstr() function locates the first occurrence of the null-terminated
     string needle in the string haystack, where not more than len characters are
     searched.  Characters that appear after a `\0' character are not searched.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (needle[0] == 0)
		return ((char *)(haystack));
	while (!(!haystack && len == 0) && haystack[i] != 0 && len > i)
	{
		j = i;
		k = 0;
		if (haystack[j] == needle[k])
		{
			while (haystack[j] == needle[k] && j != len && needle[k] != 0)
			{
				j++;
				k++;
			}
			if (needle[k] == 0)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int		main()
{
	//char *s1 = "AB";
 	//size_t max = strlen(s1) + 1;

	//printf("%s\n", strnstr(s1, s1, max));
	printf("Mia->%s\n", ft_strnstr(NULL, "mu", 0));
	printf("Suya->%s\n", strnstr(NULL, "mu", 0));

}*/