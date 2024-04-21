/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:25:00 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/01/22 16:20:06 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		negative;
	int		result;

	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	negative = 0;
	if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result == 0 || negative == 0)
		return (result);
	else
		return (-result);
}

/*
#include <stdlib.h>
#include <string.h>
int		main()
{
	char	number1[] = "    -21-47483647";
	printf("ft1  -> %d\n", ft_atoi(number1));
	printf("orig -> %d\n", atoi(number1));
	char	number2[] = "-2147483648";
	printf("ft2  -> %d\n", ft_atoi(number2));
	printf("orig -> %d\n", atoi(number2));
	char	number3[] = "  -345";
	printf("ft3  -> %d\n", ft_atoi(number3));
	printf("orig -> %d\n", atoi(number3));
	char	number4[] = "  -1234";
	printf("ft4  -> %d \n", ft_atoi(number4));
	printf("orig -> %d \n", atoi(number4));
	char	number5[] = "0";
	printf("ft5  -> %d\n", ft_atoi(number5));
	printf("orig -> %d\n", atoi(number5));
	char	number6[] = "  -0";
	printf("ft6  -> %d\n", ft_atoi(number6));
	printf("orig -> %d\n", atoi(number6));
	char	number7[] = "  12r453";
	printf("ft6  -> %d\n", ft_atoi(number7));
	printf("orig -> %d\n", atoi(number7));
	char	number8[] = "  2147483648";
	printf("ft6  -> %d\n", ft_atoi(number8));
	printf("orig -> %d\n", atoi(number8));
}*/
