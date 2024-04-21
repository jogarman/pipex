/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 08:31:08 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/15 20:01:45 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Iterates the list ’lst’ and applies the function ’f’ on the content of each
node.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

/*
void	f(unsigned int len, char *str)
{

	unsigned int	i;
	char			*ret;

	ret = malloc(len * sizeof(char));
	i = 0;
	while (i < len)
	{
		ret[i] = ft_toupper(str[i]);
		printf("%c\n", ret[i]);
		i++;
	}
	ret[i] = '\0';

}


int main()
{

	ft_striteri("hoLa", f);
	return (0);
}*/
