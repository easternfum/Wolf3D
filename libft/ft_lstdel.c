/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:07:38 by kfum              #+#    #+#             */
/*   Updated: 2021/11/29 11:13:18 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*newlist;
	t_list	*templist;

	templist = *alst;
	while (templist)
	{
		newlist = templist->next;
		del(templist->content, templist->content_size);
		free (templist);
		templist = newlist;
	}
	*alst = NULL;
}
