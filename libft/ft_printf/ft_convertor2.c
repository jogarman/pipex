/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:04:45 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/12 20:14:59 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wf_unsg(unsigned int a)
{
	return (ft_putunsgnbr_fd(a, 1));
}

size_t	wf_x_lw(unsigned int a)
{
	return (ft_dec_to_hex(a, 0));
}

size_t	wf_x_up(unsigned int a)
{
	return (ft_dec_to_hex(a, 1));
}

size_t	wf_ptr(size_t a)
{
	write(1, "0x", 2);
	return (ft_dec_to_hex(a, 0) + 2);
}
