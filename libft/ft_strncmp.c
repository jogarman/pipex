/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:25:33 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/01/23 17:28:45 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (i < (n - 1) && s1_temp[i] != '\0' && s2_temp[i] != '\0'
		&& s1_temp[i] == s2_temp[i])
	{
		i++;
	}
	return (s1_temp[i] - s2_temp[i]);
}

/*
#include <stdio.h>
#include <string.h>
int	main()
{
	printf("o__->%d\n", strncmp("\1", "\7", 5));
	printf("ft_->%d", ft_strncmp("\1", "\7", 5));
	return (0);
}
*/