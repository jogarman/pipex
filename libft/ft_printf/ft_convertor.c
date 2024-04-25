/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:00:48 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/04/23 15:35:02 by jgarcia3         ###   ########.fr       */
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
	return (ft_putchar_fd(a, STDOUT_FILENO), 1);
}

int	wf_str(char *a)
{
	if (a == NULL)
	{
		write(STDOUT_FILENO, "(null)", 6);
		return (6);
	}
	write(STDOUT_FILENO, a, ft_strlen(a));
	return (ft_strlen(a));
}

int	wf_int(int a)
{
	ft_putnbr_fd((a), STDOUT_FILENO);
	return (num_len(a));
}
