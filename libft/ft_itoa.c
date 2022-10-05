/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:58:48 by kfum              #+#    #+#             */
/*   Updated: 2022/03/10 15:56:38 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int x)
{
	int	count;

	count = 0;
	if (x <= 0)
	{
		count = 1;
	}
	while (x != 0)
	{
		count++;
		x /= 10;
	}
	return (count);
}

char	*ft_itoa(int x)
{
	char	*result;
	int		i;
	int		neg;

	neg = (x < 0);
	result = (char *)ft_memalloc(sizeof(char) * (get_size(x) + 1));
	if (!result)
	{
		return (0);
	}
	if (x == 0)
		result[0] = '0';
	i = 0;
	while (x != 0)
	{
		result[i] = '0' + ft_abs(x % 10);
		x /= 10;
		i++;
	}
	if (neg)
	{
		result[i] = '-';
	}
	ft_strrev(result);
	return (result);
}
