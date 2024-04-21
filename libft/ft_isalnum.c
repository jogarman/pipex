/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:18:30 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/01/16 15:07:58 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	return (0);
}

/*
int main(void)
{
    printf("%d\n", ft_isalnum('r'));
    printf("%d\n", ft_isalnum('R'));
    printf("%d\n", ft_isalnum('6'));
    printf("%d\n", ft_isalnum(':'));
    return (0);
}
*/
