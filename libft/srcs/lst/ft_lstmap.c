/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:02:11 by ndormoy           #+#    #+#             */
/*   Updated: 2021/11/22 18:32:49 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*begin_list;

	if (!lst || !f)
		return (NULL);
	new_list = ft_lstnew((*f)(lst->content));
	if (!new_list)
		return (NULL);
	begin_list = new_list;
	lst = lst ->next;
	while (lst)
	{
		new_list ->next = ft_lstnew((*f)(lst ->content));
		if (!new_list ->next)
		{
			ft_lstclear(&begin_list, del);
			return (NULL);
		}
		new_list = new_list ->next;
		lst = lst ->next;
	}
	new_list->next = NULL;
	return (begin_list);
}
