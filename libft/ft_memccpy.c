/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:02:09 by kfum              #+#    #+#             */
/*   Updated: 2021/11/29 11:14:12 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int x, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *) dest;
	p2 = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		p1[i] = p2[i];
		if (p2[i] == (unsigned char)x)
		{
			return (&p1[i + 1]);
		}
		i++;
	}
	return (NULL);
}
