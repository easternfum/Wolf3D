/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:48:15 by kfum              #+#    #+#             */
/*   Updated: 2022/10/06 14:45:14 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
** Start of the file reading part
** Check for edge cases(unequal map, full map, oversize map)
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
		valid_check1(graph, file, maze);
		if (ft_search(file, '0'))
			flag = 1;
		maze->x++;
		if (file)
			free(file);
		if (maze->x > 15)
			print_msg(ERR_FILE);
	}
	valid_check2(maze, flag);
}

/*
** Free the value in array that's no longer needed
*/
static void	free_graph(char **graph, t_wolf *maze)
{
	int	i;

	i = 0;
	while (i < maze->x)
	{
		free (graph[i]);
		i++;
	}
	free(graph);
}

/*
** Allocate memorry for the content saving
** Check for valid map
*/
static int	check_map(t_wolf *maze, char *file)
{
	int		fd;
	char	**graph;

	graph = (char **)malloc(sizeof(char *) * 225);
	if (!graph)
		print_msg(ERR_INIT);
	ft_bzero(graph, 225);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_msg(ERR_FILE);
	maze->x = 0;
	return_x(maze, graph, fd, file);
	if (ft_search(graph[maze->x - 1], '0'))
		print_msg(ERR_FILE);
	graph[maze->x] = 0;
	maze->matrix = get_value(graph, maze);
	if (!maze->matrix)
		print_msg(ERR_INIT);
	maze->map_size = maze->x * maze->y;
	free_graph(graph, maze);
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
