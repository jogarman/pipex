/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:05:23 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/01/23 16:14:55 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * 	 MAN
 *	 strlcat() appends string src to the end of dst.  It will append at most
 *	 dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
 *	 dstsize is 0 or the original dst string was longer than dstsize (in
 *	 practice this should not happen as it means that either dstsize is
 *	 incorrect or that dst is not a proper string).
	 Return:
	 For strlcat() that means the initial length of dst plus the length of src.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		n;
	size_t	j;

	if (dstsize == 0)
		return (ft_strlen(src));
	j = 0;
	i = ft_strlen(dst);
	n = 0;
	while (dst[j] != '\0' && j < dstsize)
		j++;
	while ((src[n] != '\0') && (i < dstsize - 1))
	{
		dst[i] = src[n];
		i++;
		n++;
	}
	dst[i] = '\0';
	return (j + ft_strlen(src));
}

/*
#include <string.h>
int	main()
{
	char	dest[8] = "aaaa";
	char	dest2[8] = "aaaa";
	char const src[] = "bbbbb";

	printf("return strlcat.c: %lu\n", strlcat(dest, src, 0));
	printf("dest 1: %s\n", dest);

	printf("return ft_strlcat.c:  %lu\n", ft_strlcat(dest2, src, 0));
	printf("dest_2: %s\n", dest2);

	return(0);
}
*/