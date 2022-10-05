/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:48:46 by kfum              #+#    #+#             */
/*   Updated: 2021/11/25 14:44:12 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	n_dest;
	size_t	n_src;
	size_t	i;

	n_dest = ft_strlen(dest);
	n_src = ft_strlen(src);
	i = 0;
	if (n <= n_dest)
	{
		return (n_src + n);
	}
	while (src[i] && n_dest + i < n - 1)
	{
		dest[n_dest + i] = src[i];
		i++;
	}
	dest[n_dest + i] = '\0';
	return (n_dest + n_src);
}
