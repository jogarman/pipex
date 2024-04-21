/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:12:58 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/28 19:31:41 by jgarcia3         ###   ########.fr       */
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

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static long	n_to_exp(int n)
{
	long	a;

	a = 1;
	while ((long)n / a != 0)
		a *= 10;
	return (a);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	ret;
	long	exp;
	char	neg;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	i = 0;
	exp = n_to_exp(n);
	neg = '-';
	if (n < 0 && n != -2147483648)
	{
		write(fd, &neg, 1);
		i++;
	}
	while (i < (int)num_len(n) && n != -2147483648)
	{
		ret = 48 + ((ft_abs(n) % exp) / ft_pow(10, (num_len(n) - (i + 1))));
		write(fd, &ret, 1);
		exp /= 10;
		i++;
	}
}

/*
int	main()
{
	unsigned int a = 2147483648;

	ft_putnbr_fd(a, 1);
}*/
