/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:58:08 by kfum              #+#    #+#             */
/*   Updated: 2021/12/08 11:55:33 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)str1;
	p2 = (unsigned char *)str2;
	if (!n)
	{
		return (0);
	}
	while ((p1[i] && p2[i]) && (p1[i] == p2[i]))
	{
		if (i == n - 1)
		{
			return (p1[i] - p2[i]);
		}			
		i++;
	}
	return (p1[i] - p2[i]);
}
