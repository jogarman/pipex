/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:48:00 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/04 23:26:33 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_which_format(char c, va_list argument)
{
	if (c == 'c')
		return (wf_char(va_arg(argument, int)));
	else if (c == 's')
		return (wf_str(va_arg(argument, char *)));
	else if (c == 'd' || c == 'i')
		return (wf_int(va_arg(argument, int)));
	else if (c == 'u')
		return (wf_unsg(va_arg(argument, unsigned int)));
	else if (c == 'x')
		return (wf_x_lw(va_arg(argument, unsigned int)));
	else if (c == 'X')
		return (wf_x_up(va_arg(argument, unsigned int)));
	else if (c == 'p')
		return (wf_ptr(va_arg(argument, size_t)));
	return (0);
}

static void	aux(char *ptr, int *n_charact)
{
	write(STDOUT_FILENO, ptr, 1);
	*n_charact += 1;
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		n_charact;

	n_charact = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			aux((char *)&str[i], &n_charact);
		else if (str[i + 1])
		{
			if (str[i] == '%' && str[i + 1] == '%')
			{
				write(STDOUT_FILENO, "%", 1);
				n_charact++;
			}
			else
				n_charact += ft_which_format(str[i + 1], args);
			i++;
		}
		i++;
	}
	return (n_charact);
}

/*
•  %c Imprime un solo carácter.
•  %s Imprime una string (como se define por defecto en C).
• %d Imprime un número decimal (base 10).
• %i Imprime un entero en base 10.
• %u Imprime un número decimal (base 10) sin signo.
• %x Imprime un número hexadecimal (base 16) en minúsculas.
• %X Imprime un número hexadecimal (base 16) en mayúsculas.
• %p El puntero void * dado como argumento se imprime en formato hexadecimal.
• %% para imprimir el símbolo del porcentaje.
*/