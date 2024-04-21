/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:39:53 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/15 20:24:40 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*recursive(t_list **node, void (*del)(void *))
{
	t_list	*temp;

	temp = *node;
	*node = (*node)->next;
	if ((*node) != NULL)
	{
		recursive(node, del);
	}
	del(temp->content);
	free(temp);
	return (NULL);
}

/*
Delete and free node 'lst' and the rest consecutive nodes, using 'del' and free
Last node ends in NULL
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	recursive(lst, del);
	*lst = NULL;
}
/*
int main()
{
    t_list	*lista = NULL;
	t_list	*new = NULL;

	//new = malloc(sizeof(t_list));
	//new->content = "nuevo nodo";
	//new->next = NULL;

	char	*contenido1 = "Elemento 1";
	char	*contenido2 = "Elemento 2";
	char	*contenido3 = "Elemento 3";
	t_list	*dir1 = NULL;
	t_list	*dir2 = NULL;
	t_list	*dir3 = NULL;

	ft_lstadd_front(&lista, ft_lstnew(contenido3));
	dir3 = &lista;
	ft_lstadd_front(&lista, ft_lstnew(contenido2));
	dir2 = &lista;
	ft_lstadd_front(&lista, ft_lstnew(contenido1));
	dir1 = &lista;

	ft_lstclear(*dir2. )
	t_list *current = lista;
	while (current != NULL)
    {
		printf("%s\n", (char *)current->content);
        current = current->next;
    }
    return (0);
}*/
