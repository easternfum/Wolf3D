/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:17:01 by kfum              #+#    #+#             */
/*   Updated: 2021/12/08 11:39:15 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*result;

	result = dest + ft_strlen(dest);
	while (*src != '\0')
	{
		*result++ = *src++;
	}
	*result = '\0';
	return (dest);
}
