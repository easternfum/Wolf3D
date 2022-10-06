/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:44:00 by kfum              #+#    #+#             */
/*   Updated: 2021/12/08 11:34:08 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int x, size_t n)
{
	unsigned char	*newstr;
	size_t			i;

	newstr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (newstr[i] == (unsigned char)x)
		{
			return (&newstr[i]);
		}
		i++;
	}
	str = NULL;
	return (NULL);
}
