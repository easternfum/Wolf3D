/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:25:37 by kfum              #+#    #+#             */
/*   Updated: 2022/10/06 16:12:40 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
** Set player's spawning position
*/
static void	spawn_position(t_wolf *maze)
{
	int	i;
	int	j;
	int	spawn;
	int	spawn2;

	i = 1;
	while (i < maze->x - 1)
	{
		j = 1;
		while (j < maze->y - 1)
		{
			if (maze->matrix[i][j] != 1 && j != maze->y - 1)
			{
				spawn = i;
				spawn2 = j;
				i = maze->x - 2;
				break ;
			}
			j++;
		}
		i++;
	}
	maze->player.x = spawn + 0.5;
	maze->player.y = spawn2 + 0.5;
}

/*
**	Initialize player's setting, ray distance and frame time
*/
void	init_player(t_wolf *maze)
{
	spawn_position(maze);
	maze->player.dir_x = 1;
	maze->player.plane_x = 0;
	maze->player.plane_y = -0.66;
	maze->player.speed_set = 3;
	maze->ray.time = 0.0;
	maze->ray.old_time = 0.0;
	maze->ray.delta_x = 1.5;
	maze->ray.delta_y = 1.5;
}

/*
** Initialize the wall and the empty field
*/
void	init_wall(t_wolf *maze)
{
	int	i;
	int	j;

	i = 0;
	maze->map = (int **)malloc(sizeof(int *) * maze->map_size);
	if (!maze->map)
		print_msg(ERR_INIT);
	while (i < maze->x)
	{
		j = 0;
		maze->map[i] = (int *)malloc(sizeof(int) * maze->map_size);
		if (!maze->map[i])
			print_msg(ERR_INIT);
		while (j < maze->y)
		{
			if (maze->matrix[i][j] == 1)
				maze->map[i][j] = 1;
			else
				maze->map[i][j] = 0;
			j++;
		}
		i++;
	}
}

/*
** Update the window frame by time
*/
void	frame_update(t_wolf *maze)
{
	double	temp;

	maze->ray.old_time = maze->ray.time;
	maze->ray.time = clock();
	temp = (maze->ray.time - maze->ray.old_time) / CLOCKS_PER_SEC;
	maze->ray.frame_time = temp;
	maze->player.speed = maze->ray.frame_time;
	maze->player.speed *= maze->player.speed_set;
}
