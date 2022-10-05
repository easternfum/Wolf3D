/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:58:04 by kfum              #+#    #+#             */
/*   Updated: 2022/03/15 11:18:05 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_check(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static int	end_check(const char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i > 0)
	{
		if (!ft_isspace(str[i]))
		{
			return (i);
		}
		i--;
	}
	return (-1);
}

char	*ft_strtrim(const char *s)
{
	char	*result;
	int		x;
	int		y;

	if (!s)
	{
		return (0);
	}
	x = start_check(s);
	y = end_check(s);
	if (x == -1 || y == -1)
	{
		return (ft_strnew(0));
	}
	result = ft_strsub(s, x, (y - x) + 1);
	return (result);
}
