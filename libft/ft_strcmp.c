/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:03:47 by kfum              #+#    #+#             */
/*   Updated: 2021/12/08 11:44:14 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*newstr1;
	unsigned char	*newstr2;

	newstr1 = (unsigned char *)str1;
	newstr2 = (unsigned char *)str2;
	while (*newstr1 && *newstr2 && *newstr1 == *newstr2)
	{
		newstr1++;
		newstr2++;
	}
	return (*newstr1 - *newstr2);
}
