/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:38:46 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/07 10:55:35 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	jump;

	jump = '\n';
	i = 0;
	ft_putstr_fd(s, fd);
	write(fd, &jump, 1);
}

/*
int	main()
{
	ft_putendl_fd("hola", 2);
	ft_putendl_fd("hola", 2);
	return (0);
}*/
