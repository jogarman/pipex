/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:46:32 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/04/25 15:22:39 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **ptr, int j)
{
	while (j >= 0)
	{
		free(ptr[j]);
		j--;
	}
	free(ptr);
}

static int	is_flank(char a, char b, char delimitater)
{
	if (b == delimitater || b == '\0')
	{
		if (a != delimitater)
			return (1);
	}
	return (0);
}

static int	number_of_words(char const *s, char c)
{
	int		i;
	int		n_words;

	n_words = 0;
	i = 1;
	while (s[i - 1] != 0)
	{
		if (is_flank(s[i - 1], s[i], c))
		{
			n_words++;
		}
		i++;
	}
	return (n_words);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ret;
	int		j;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	ret = (char **)malloc((number_of_words(s, c) + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	while (s[i] == c && s[i] != '\0')
		s++;
	while (s[i] != 0)
	{
		if (i == 0 || (s[i - 1] == c && s[i] != c))
		{
			ret[j++] = ft_substr(s, i, (word_len(s + i, c)));
			if (ret[j - 1] == NULL)
				return (ft_free(ret, j - 1), (NULL));
		}
		i++;
	}
	ret[j] = NULL;
	return (ret);
}

/* #include <stdio.h>
int		main()
{
	char	**string = ft_split("hola", ' ');
	int		i = 0;

	while (string[i] != NULL)
	{
		printf("%d>%s<\n",i, string[i]);
		i++;
	}
	if (string[i] == NULL)
	{
		printf("%d>Null\n", i);
	}
} */
