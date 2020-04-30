/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:38:36 by dchampda          #+#    #+#             */
/*   Updated: 2020/04/30 15:41:16 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem_before;

	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		del((*lst)->content);
		elem_before = *lst;
		*lst = elem_before->next;
		free(elem_before);
	}
	*lst = NULL;
}
