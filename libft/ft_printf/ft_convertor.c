/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:00:48 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/08 11:54:00 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	wf_char(char a)
{
	return (ft_putchar_fd(a, 1), 1);
}

int	wf_str(char *a)
{
	if (a == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, a, ft_strlen(a));
	return (ft_strlen(a));
}

int	wf_int(int a)
{
	ft_putnbr_fd((a), 1);
	return (num_len(a));
}
