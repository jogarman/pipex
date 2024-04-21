/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:32:54 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/08 11:55:00 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* return n of  characters and print in hexa n given */

#include "ft_printf.h"

size_t	ft_dec_to_hex(size_t n, int caps)
{
	char	*base;
	size_t	ret;

	ret = 0;
	if (caps == 0)
		base = "0123456789abcdef";
	if (caps == 1)
		base = "0123456789ABCDEF";
	if (caps < 0 || caps > 1)
		return (-1);
	if (n < 16)
	{
		write(1, &base[n % 16], 1);
		return (1);
	}
	ret += ft_dec_to_hex(n / 16, caps);
	ret += ft_dec_to_hex(n % 16, caps);
	return (ret);
}

/*
int main()
{
	printf("\n%d\n", ft_dec_to_hex(-1, 0));
} */
