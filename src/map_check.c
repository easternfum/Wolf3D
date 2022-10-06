/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:05:57 by kfum              #+#    #+#             */
/*   Updated: 2022/10/06 14:24:00 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
** Duplicate file content and put it into array
** Check the empty hole on side walls
*/
char	*valid_check1(char **graph, char *file, t_wolf *maze)
{
	graph[maze->x] = ft_strdup(file);
	if (!graph[maze->x])
		print_msg(ERR_INIT);
	if (ft_search(graph[0], '0') || graph[maze->x][0] == '0'
		|| graph[maze->x][ft_strlen(graph[maze->x]) - 1] == '0')
		print_msg(ERR_FILE);
	return (graph[maze->x]);
}

/*
** Check for smallest valid map and full map
*/
void	valid_check2(t_wolf *maze, int flag)
{
	if (2 > maze->x)
		print_msg(ERR_FILE);
	if (flag == 0)
		print_msg(ERR_FILE);
}

/*
** Allocate memory to store file content
*/
static int	*array_malloc(int **array, int len, int i)
{
	array[i] = (int *)malloc(sizeof(int) * len);
	if (!array[i])
		print_msg(ERR_INIT);
	return (array[i]);
}

/*
** Free the content in array that's no longer needed
*/
static void	free_split(char **split, int j, int k)
{
	k = 0;
	while (k <= j)
	{
		free(split[k]);
		k++;
	}
	free(split);
}

/*
** Save file content into array
** Filter the ' ' out and convert the content into integer
*/
int	**get_value(char **graph, t_wolf *maze)
{
	int		i;
	int		j;
	int		len;
	int		**array;
	char	**split;

	array = (int **)malloc(sizeof(int *) * maze->x);
	if (!array)
		print_msg(ERR_INIT);
	i = 0;
	while (i < maze->x)
	{
		j = -1;
		len = 0;
		split = ft_strsplit(graph[i], ' ');
		while (split[len])
			len++;
		array_malloc(array, len, i);
		while (split[++j])
			array[i][j] = ft_atoi(split[j]);
		i++;
		free_split(split, j, len);
	}
	maze->y = len;
	return (array);
}
