/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:53:03 by kfum              #+#    #+#             */
/*   Updated: 2021/12/08 11:35:15 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)str1;
	p2 = (unsigned char *)str2;
	if (!str1 && !str2)
		return (NULL);
	if (p1 < p2)
	{
		ft_memcpy(p1, p2, n);
	}
	else
	{
		i = n;
		while (i > 0)
		{
			p1[i - 1] = p2[i - 1];
			i--;
		}
	}
	return (p1);
}
