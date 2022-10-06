/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:31:24 by kfum              #+#    #+#             */
/*   Updated: 2021/11/25 10:47:40 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *word)
{
	size_t	i;

	i = 0;
	if (!*word)
	{
		return ((char *)src);
	}
	while (i < ft_strlen(src))
	{
		if (ft_strncmp((char *)&src[i], word, ft_strlen(word)) == 0)
		{
			return ((char *)&src[i]);
		}
		i++;
	}	
	return (0);
}
