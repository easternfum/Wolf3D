/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:09:20 by kfum              #+#    #+#             */
/*   Updated: 2021/12/08 11:19:11 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del_elem(void *content, size_t content_size)
{
	(void) content_size;
	free(content);
	content = NULL;
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*finallist;
	t_list	*newlist;
	t_list	*templist;

	if (!lst || !f)
		return (NULL);
	finallist = f(lst);
	lst = lst->next;
	while (lst)
	{
		newlist = f(lst);
		if (!newlist)
		{
			ft_lstdel(&newlist, &del_elem);
			return (NULL);
		}
		templist = finallist;
		while (templist->next)
		{
			templist = templist->next;
		}
		templist->next = newlist;
		lst = lst->next;
	}
	return (finallist);
}
