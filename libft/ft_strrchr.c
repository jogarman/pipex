/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:26:16 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/01/23 16:26:12 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0 || i == 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	return (NULL);
}

/*
#include <string.h>
int	main()
{
	const char string[] = "oaaa";
	char	character = 'o';

	printf("%s\n", ft_strrchr(string, character));
	printf("%s", strrchr(string, character));
	return (0);
}
*/