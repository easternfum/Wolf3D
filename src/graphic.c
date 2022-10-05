/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:18:26 by kfum              #+#    #+#             */
/*   Updated: 2022/09/29 16:15:29 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
** Initialize colors to graphic
*/
static void	init_color(t_wolf *maze, int x, int y, int color)
{
	char	*graph;
	int		g;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		graph = mlx_get_data_addr(maze->graphic, &g, &g, &g);
		g = WIDTH * y * 4 + x * 4;
		graph[g + 0] = (int)((color >> 16) & 0xFF);
		graph[g + 1] = (int)((color >> 8) & 0xFF);
		graph[g + 2] = (int)((color) & 0xFF);
	}
}

/*
** Initialize colors to floor and ceiling
*/
void	floor_ceiling(t_wolf *maze, int x)
{
	int		y;
	int		z;
	void	*temp;
	int		b;

	if (maze->end < 0)
		maze->end = HEIGHT;
	y = maze->end;
	z = HEIGHT - maze->start;
	while (y <= HEIGHT)
	{
		init_color(maze, x, y, 0x0F9E79F);
		y++;
	}
	y = 0;
	while (y < z)
	{
		init_color(maze, x, y, 0x0797D7F);
		y++;
	}
}

static void	set_wall_color(t_wolf *maze)
{
	if (maze->ray.direction == 1 && maze->ray.dir_y < 0)
		maze->color = (maze->color >> 5) & 0x0196F3D;
	else if (maze->ray.dir_x < 5 && maze->ray.direction == 1)
		maze->color = (maze->color >> 5) & 0x01F618D;
	else if (maze->ray.direction == 0 && maze->ray.dir_x >= 0)
		maze->color = (maze->color >> 5) & 0x05D6D7E;
	else
		maze->color = (maze->color >> 5) & 0x095A5A6;
}

/*
** Set the texture to wall and change color base on direction
*/
void	insert_texture(t_wolf *maze, int x)
{
	if (maze->ray.direction == 0)
		maze->ray.wall = maze->ray.pos_y + maze->ray.wall_dist
			* maze->ray.dir_y;
	else
		maze->ray.wall = maze->ray.pos_x + maze->ray.wall_dist
			* maze->ray.dir_x;
	maze->ray.wall -= floor((maze->ray.wall));
	maze->ray.text_x = (int)(maze->ray.wall * (double)(maze->t_w[0]));
	while (maze->start != maze->end)
	{
		maze->dist = maze->start * 256 - HEIGHT * 128 + maze->ray.wall_height
			* 128;
		maze->ray.text_y = ((maze->dist * maze->t_h[0]) / maze->ray.wall_height)
			/ 256;
		maze->color = maze->texture[0][maze->t_h[0] * maze->ray.text_y
			+ maze->ray.text_x];
		set_wall_color(maze);
		if (maze->ray.wall_height * maze->ray.text_y + maze->ray.text_x < 0)
			return ;
		maze->data[x + WIDTH * maze->start] = maze->color;
		maze->start++;
	}
}

/*
** Set texture graphic to structure
*/
void	xpm_file(t_wolf *maze)
{
	void	*temp;
	int		b;

	maze->mlx = mlx_init();
	maze->window = mlx_new_window(maze->mlx, WIDTH, HEIGHT, WOLF);
	maze->graphic = mlx_new_image(maze->mlx, WIDTH, HEIGHT);
	maze->texture = (int **)malloc(sizeof(int *) * 1);
	temp = mlx_xpm_file_to_image(maze->mlx, "texture/wall.xpm",
			&(maze->t_h[0]), &(maze->t_w[0]));
	maze->texture[0] = (int *)mlx_get_data_addr(temp, &b, &b, &b);
	maze->data = (int *)mlx_get_data_addr(maze->graphic, &b, &b, &b);
}
