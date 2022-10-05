/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:48:15 by kfum              #+#    #+#             */
/*   Updated: 2022/10/04 15:10:43 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"
#include <stdio.h>

/*
** Read file content and split it to array
*/
static int	**get_value(char **graph, t_wolf *maze)
{
	int		i;
	int		j;
	int		len;
	int		**array;
	char	**split;

	array = (int **)malloc(sizeof(int *) * maze->x);
	i = 0;
	while (i < maze->x)
	{
		j = -1;
		len = 0;
		split = ft_strsplit(graph[i], ' ');
		while (split[len])
			len++;
		array[i] = (int *)malloc(sizeof(int) * len);
		if (!array[i])
			return (0);
		while (split[++j])
			array[i][j] = ft_atoi(split[j]);
		i++;
	}
	maze->y = len;
	return (array);
}

/*
** Part of check_map function, check count
*/
static int	null_return_check(char **graph, t_wolf *maze)
{
	if (!graph[maze->x])
	{
		print_msg(ERR_INIT);
		exit(0);
	}
	return (maze->x);
}

/*
** Part of check_map function, return maze->x value
*/
static void	return_x(t_wolf *maze, char **graph, int fd, char *file)
{
	int		count;
	int		flag;

	count = -1;
	flag = 0;
	while (get_next_line(fd, &file) > 0)
	{
		if (count == -1)
			count = ft_count(file, ' ');
		if (ft_count(file, ' ') != count || count == 0)
			print_msg(ERR_FILE);
		graph[maze->x] = ft_strdup(file);
		null_return_check(graph, maze);
		if (ft_search(graph[0], '0') || graph[maze->x][0] == '0'
			|| graph[maze->x][ft_strlen(graph[maze->x]) - 1] == '0')
			print_msg(ERR_FILE);
		if (ft_search(file, '0'))
			flag = 1;
		maze->x++;
	}
	if (flag == 0)
		print_msg(ERR_FILE);
}

/*
** Check valid map, only square map is allowed
*/
static int	check_map(t_wolf *maze, char *file)
{
	int		fd;
	char	**graph;

	graph = (char **)malloc(sizeof(char *) * 1000);
	ft_bzero(graph, 1000);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_msg(ERR_FILE);
	maze->x = 0;
	return_x(maze, graph, fd, file);
	graph[maze->x] = 0;
	maze->matrix = get_value(graph, maze);
	maze->map_size = maze->x * maze->y;
	if (ft_search(graph[maze->x - 1], '0'))
		print_msg(ERR_FILE);
	if (3 > maze->map_size || maze->map_size > 225)
		print_msg(ERR_FILE);
	init_wall(maze);
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_wolf	maze;

	(void)av;
	if (ac == 2)
	{
		check_map(&maze, av[1]);
		init_player(&maze);
		xpm_file(&maze);
		mlx_hook(maze.window, 2, 3, move_setting, &maze);
		mlx_hook(maze.window, 17, 4, red_cross, &maze);
		mlx_loop_hook(maze.mlx, init_window, &maze);
		mlx_loop(maze.mlx);
	}
	print_msg(ERR_PARM);
	return (0);
}
