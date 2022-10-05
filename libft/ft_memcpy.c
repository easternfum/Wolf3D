/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:29:30 by kfum              #+#    #+#             */
/*   Updated: 2021/11/29 11:15:25 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	if (!p1 && !p2)
	{
		return (NULL);
	}
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (p1);
}
