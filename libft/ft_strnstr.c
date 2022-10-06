/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:20:30 by kfum              #+#    #+#             */
/*   Updated: 2021/12/08 12:14:46 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *word, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*word)
	{
		return ((char *)src);
	}
	while (src[i] && i < n)
	{
		j = 0;
		if (src[i] == word[j])
		{
			while (i + j < n && src[i + j] == word[j])
			{
				j++;
				if (!word[j])
				{
					return ((char *)&src[i]);
				}
			}
		}
		i++;
	}
	return (0);
}
