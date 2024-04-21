/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsgnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:51:39 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/29 09:34:03 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pow(unsigned int n, int m)
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

static int	num_len(unsigned int n)
{
	long	j;
	int		len;

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

static long	n_to_exp(unsigned int n)
{
	long	a;

	a = 1;
	while ((long)n / a != 0)
		a *= 10;
	return (a);
}

int	ft_putunsgnbr_fd(unsigned int n, int fd)
{
	int		i;
	char	ret;
	long	exp;

	i = 0;
	exp = n_to_exp(n);
	while (i < (int)num_len(n))
	{
		ret = 48 + ((n % exp) / ft_pow(10, (num_len(n) - (i + 1))));
		write(fd, &ret, 1);
		exp /= 10;
		i++;
	}
	return (i);
}

/*
int	main()
{
    ft_putunsgnbr_fd(4294967290, 1);
}*/
