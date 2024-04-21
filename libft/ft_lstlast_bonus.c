/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:12:03 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/13 17:31:14 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
int main()
{
    t_list	*lista = NULL;
    char	*contenido1 = "Elemento 1";
    char	*contenido2 = "Elemento 2";
    char	*contenido3 = "Elemento 3";

    ft_lstadd_front(&lista, ft_lstnew(contenido3));
    ft_lstadd_front(&lista, ft_lstnew(contenido2));
    ft_lstadd_front(&lista, ft_lstnew(contenido1));

    t_list *current = lista;
    while (current != NULL)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }
	printf("%s", ft_lstlast(lista)->content);
    return (0);
}*/
