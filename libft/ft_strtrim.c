/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:42:44 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/13 18:47:20 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	left_to_right(const char *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
		{
			j++;
		}
	}
	return (i);
}

static int	right_to_left(const char *s1, char const *set)
{
	int	f;
	int	j;

	f = ft_strlen(s1) - 1;
	j = 0;
	while (f >= 0 && set[j] != '\0')
	{
		if (s1[f] == set[j])
		{
			f--;
			j = 0;
		}
		else
		{
			j++;
		}
	}
	if (f == -1)
		f = 0;
	return (f);
}

/*
Allocates (with malloc(3)) and returns a copy of ’s1’
with the characters specified in ’set’ removed from the
beginning and the end of the string.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		f;
	char	*ret;
	int		ret_size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = left_to_right(s1, set);
	f = right_to_left(s1, set);
	if ((f - i) < 0 || (s1[0] == '\0'))
		ret_size = 1;
	else
		ret_size = (f - i) + 2;
	ret = (char *) malloc(ret_size);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, (char *)(s1 + i), (size_t)ret_size);
	return (ret);
}
/*
int	main()
{
	char *s1 = "";
 	char *s2 = "";

 	char *a = ft_strtrim(s1, s2);
	printf("str->%s<", a);
	//printf("len-> %zu", ft_strlen(a));
	//system("leaks a.out");
}*/