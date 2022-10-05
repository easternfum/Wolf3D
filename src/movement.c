/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:05:11 by kfum              #+#    #+#             */
/*   Updated: 2022/09/29 16:20:02 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
** Move forward movement
*/
static void	move_forward(t_player *p, int **map)
{
	if (!map[(int)(p->x + p->dir_x * p->speed)][(int)(p->y)])
		p->x += p->dir_x * p->speed;
	if (!map[(int)(p->x)][(int)(p->y + p->dir_y * p->speed)])
		p->y += p->dir_y * p->speed;
}

/*
** Move backward movement
*/
static void	move_backward(t_player *p, int **map)
{
	if (!map[(int)(p->x - p->dir_x * p->speed)][(int)(p->y)])
		p->x -= p->dir_x * p->speed;
	if (!map[(int)(p->x)][(int)(p->y - p->dir_y * p->speed)])
		p->y -= p->dir_y * p->speed;
}

/*
** Rotate left movement
*/
static void	rotate_left(t_player *p)
{
	p->old_dir = p->dir_x;
	p->dir_x = p->dir_x * cos(0.05) - p->dir_y * sin(0.05);
	p->dir_y = p->old_dir * sin(0.05) + p->dir_y * cos(0.05);
	p->old_plane = p->plane_x;
	p->plane_x = p->plane_x * cos(0.05) - p->plane_y * sin(0.05);
	p->plane_y = p->old_plane * sin(0.05) + p->plane_y * cos(0.05);
}

/*
** Rotate right movement
*/
static void	rotate_right(t_player *p)
{
	p->old_dir = p->dir_x;
	p->dir_x = p->dir_x * cos(-0.05) - p->dir_y * sin(-0.05);
	p->dir_y = p->old_dir * sin(-0.05) + p->dir_y * cos(-0.05);
	p->old_plane = p->plane_x;
	p->plane_x = p->plane_x * cos(-0.05) - p->plane_y * sin(-0.05);
	p->plane_y = p->old_plane * sin(-0.05) + p->plane_y * cos(-0.05);
}

/*
** Key input setting
*/
int	move_setting(int key, t_wolf *maze)
{
	if (key == 53)
		print_msg(EXIT);
	if (key == 126)
		move_forward(&(maze->player), maze->map);
	if (key == 125)
		move_backward(&(maze->player), maze->map);
	if (key == 123)
		rotate_left(&(maze->player));
	if (key == 124)
		rotate_right(&(maze->player));
	return (0);
}
