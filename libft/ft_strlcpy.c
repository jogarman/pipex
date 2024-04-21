/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:49:07 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/27 17:35:04 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings with
     the same input parameters and output result as snprintf(3).  They are
     designed to be safer, more consistent, and less error prone replacements
     for the easily misused functions strncpy(3) and strncat(3).

     strlcpy() and strlcat() take the full size of the destination buffer and
     guarantee NUL-termination if there is room.  Note that room for the NUL
     should be included in dstsize.

     strlcpy() copies up to dstsize - 1 characters from the string src to dst,
     NUL-terminating the result if dstsize is not 0.

     strlcat() appends string src to the end of dst.  It will append at most
     dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
     dstsize is 0 or the original dst string was longer than dstsize (in prac-
     tice this should not happen as it means that either dstsize is incorrect
     or that dst is not a proper string).

     If the src and dst strings overlap, the behavior is undefined.
	 */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	i = 0;
	while ((i < dstsize - 1) && (src[i] != 0))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <string.h>
#include <unistd.h>
int main()
{
	char	dest[20];
	char	dest2[20];
	//char	dest[15];



	printf("return strlcpy.c%lu\n", strlcpy(dest, "hola mundo", size));
	printf("dest 1: %s\n", dest);

	printf("return ft_strlcpy.c:  %lu\n", ft_strlcpy(dest2, "hola mundo", size));
	printf("dest_2: %s\n", dest2);

    printf("ft_____ ->%lu\n",ft_strlcpy(dest, "12345", 0));
    write(1, "\n", 1);
    write(1, dest, 15);
    write(1, "\n", 1);
	printf("original->: %lu\n", strlcpy(dest2, "12345", 0));
    write(1, "\n", 1);
    write(1, dest2, 15);
	return(0);
}*/