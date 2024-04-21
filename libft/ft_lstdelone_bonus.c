/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:04:56 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/13 16:25:06 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/*
int		main()
{
	t_list	*lista = NULL;

    ft_lstadd_front(&lista, ft_lstnew(contenido3));
    ft_lstadd_front(&lista, ft_lstnew(contenido2));
    ft_lstadd_front(&lista, ft_lstnew(contenido1));

	t_list *current = lista;
	while (current != NULL)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }
}*/
