/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:40:30 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/12 18:47:30 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(int n, int m)
{
	int	i;
	int	result;

	result = 1;
	i = 1;
	if (m == 0)
		return (1);
	if (n == 0)
		return (0);
	while (i <= m)
	{
		result = result * n;
		i++;
	}
	return (result);
}

static int	num_len(int n)
{
	long	j;
	int		len;
	int		neg;

	neg = 0;
	j = 1;
	len = 0;
	while ((long)n / j != 0)
	{
		j *= 10;
		len ++;
	}
	if (n < 0)
		len++;
	if (n == 0)
		len = 1;
	return (len);
}

/* 	n_to_exp:
 * if n = 54    ret-> 100
 * if n = 6.543 ret-> 10.000 */

static long	n_to_exp(int n)
{
	long	a;

	a = 1;
	while ((long)n / a != 0)
		a *= 10;
	return (a);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	long	exp;

	ret = malloc((num_len(n) + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	if (n == -2147483648)
		ft_strlcpy(ret, "-2147483648", 12);
	if (n == -2147483648)
		return (ret);
	i = 0;
	exp = n_to_exp(n);
	if (n < 0)
		ret[i++] = '-';
	while (i < (int)num_len(n))
	{
		ret[i] = 48 + ((ft_abs(n) % exp) / ft_pow(10, (num_len(n) - (i + 1))));
		exp /= 10;
		i++;
	}
	ret[i] = ('\0');
	return (ret);
}

/*
int	main()
{
	printf("ft_itoa -> %s\n", ft_itoa(-2147483648));
	printf("ft_itoa -> %s\n", ft_itoa(-2147483648LL));
	printf("ft_itoa -> %s\n", ft_itoa(2147483647));
	printf("ft_itoa -> %s\n", ft_itoa(0));
	printf("ft_itoa -> %s\n", ft_itoa(-1));
	printf("ft_itoa -> %s\n", ft_itoa(1));
}*/
