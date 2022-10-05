/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:51:57 by kfum              #+#    #+#             */
/*   Updated: 2021/12/08 11:53:56 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p1;
	char	*p2;
	char	*result;

	if (!s || !f)
	{
		return (NULL);
	}
	result = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
	{
		return (NULL);
	}
	p1 = (char *)s;
	p2 = result;
	while (*p1)
	{
		*(p2++) = f(*(p1++));
	}
	return (result);
}
