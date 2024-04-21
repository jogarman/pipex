/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:02:47 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/04 17:42:07 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
     The strdup() function allocates sufficient memory
     for a copy of the string s1, does the copy, and
     returns a pointer to it.  The pointer may subse-
     quently be used as an argument to the function
     free(3).

     If insufficient memory is available, NULL is
     returned and errno is set to ENOMEM.
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
/*
int	main()
{
	printf("%s", ft_strdup(""));
}*/