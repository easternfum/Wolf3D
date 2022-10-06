/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:37:45 by kfum              #+#    #+#             */
/*   Updated: 2022/10/06 16:13:06 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
** Initialize the raycast starting value
*/
static void	init_raycast(t_player *p, t_raycast *ray, int x)
{
	p->camera = 2 * x / (double)(WIDTH) - 1;
	ray->pos_x = p->x;
	ray->pos_y = p->y;
	ray->dir_x = p->dir_x + p->plane_x * p->camera;
	ray->dir_y = p->dir_y + p->plane_y * p->camera;
	ray->x = (int)(ray->pos_x);
	ray->y = (int)(ray->pos_y);
	ray->delta_x = ray->dir_y * ray->dir_y;
	ray->delta_x = ray->delta_x / (ray->dir_x * ray->dir_x);
	ray->delta_x = sqrt(1 + ray->delta_x);
	ray->delta_y = ray->dir_x * ray->dir_x;
	ray->delta_y = ray->delta_y / (ray->dir_y * ray->dir_y);
	ray->delta_y = sqrt(ray->delta_y + 1);
}

/*
** Set the distance between player and objects
*/
static void	init_distance(t_raycast *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->dist_x = (ray->pos_x - ray->x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->dist_x = (ray->x + 1.0 - ray->pos_x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->dist_y = (ray->pos_y - ray->y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->dist_y = (ray->y + 1.0 - ray->pos_y) * ray->delta_y;
	}
}

/*
** Set the wall collision
*/
static void	wall_collision(t_raycast *ray, int **level)
{
	while (1)
	{
		if (ray->dist_x < ray->dist_y)
		{
			ray->dist_x += ray->delta_x;
			ray->x += ray->step_x;
			ray->direction = 0;
		}
		else
		{
			ray->dist_y += ray->delta_y;
			ray->y += ray->step_y;
			ray->direction = 1;
		}
		if ((level[ray->x][ray->y] > 0)
			&& (level[ray->x][ray->y] != 9))
			break ;
	}
}

/*
** Set the wall distance base on the raycast value
*/
static void	wall_dist(t_wolf *maze, t_raycast *ray)
{
	if (ray->direction == 0)
	{
		ray->wall_dist = (ray->x - ray->pos_x + (1 - ray->step_x) / 2);
		ray->wall_dist /= ray->dir_x;
	}
	else
	{
		ray->wall_dist = (ray->y - ray->pos_y + (1 - ray->step_y) / 2);
		ray->wall_dist /= ray->dir_y;
	}
	ray->wall_height = (int)(HEIGHT / ray->wall_dist);
	maze->ray.wall_height = (int)(HEIGHT / maze->ray.wall_dist);
	maze->start = -maze->ray.wall_height / 2 + HEIGHT / 2;
	if (maze->start < 0)
		maze->start = 0;
	maze->end = maze->ray.wall_height / 2 + HEIGHT / 2;
	if (maze->end >= HEIGHT)
		maze->end = HEIGHT - 1;
}

/*
** Initialize window output(ray, texture, time frame)
*/
int	init_window(t_wolf *maze)
{
	int	x;

	x = 0;
	clear_graph(maze);
	while (x < WIDTH)
	{
		init_raycast(&(maze->player), &(maze->ray), x);
		init_distance(&(maze->ray));
		wall_collision(&(maze->ray), maze->map);
		wall_dist(maze, &(maze->ray));
		insert_texture(maze, x);
		floor_ceiling(maze, x);
		x++;
	}
	frame_update(maze);
	mlx_put_image_to_window(maze->mlx, maze->window, maze->graphic, 0, 0);
	control_instruction(maze);
	return (0);
}
