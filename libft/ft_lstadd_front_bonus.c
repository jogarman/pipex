/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 08:13:03 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/08 09:58:41 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
int main()
{
	t_list	*lista = NULL;
	char	*contenido = "Hola";
	ft_lstadd_front(&lista, ft_lstnew(contenido));
	printf("%s", (char *)lista->content);
}*/
