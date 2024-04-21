/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:49:13 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/04/21 19:55:25 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

size_t	ft_dec_to_hex(size_t n, int caps);
int		ft_printf(char const *str, ...);
int		ft_putunsgnbr_fd(unsigned int n, int fd);

int		wf_char(char a);
int		wf_str(char *a);
int		wf_int(int a);
int		wf_unsg(unsigned int a);
size_t	wf_x_lw(unsigned int a);
size_t	wf_x_up(unsigned int a);
size_t	wf_ptr(size_t a);

#endif