/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:44:07 by kfum              #+#    #+#             */
/*   Updated: 2022/10/06 16:11:36 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define WIDTH 1580
# define HEIGHT 1000
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "msg.h"

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		old_dir;
	double		plane_x;
	double		plane_y;
	double		old_plane;
	double		speed;
	double		speed_set;
	double		camera;
}				t_player;

typedef struct s_raycast
{
	int			x;
	int			y;
	double		pos_x;
	double		pos_y;
	int			direction;
	double		dir_x;
	double		dir_y;
	double		dist_x;
	double		dist_y;
	double		delta_x;
	double		delta_y;
	int			step_x;
	int			step_y;
	double		wall;
	double		wall_dist;
	int			wall_height;
	int			text_x;
	int			text_y;
	double		frame_time;
	double		time;
	double		old_time;
}				t_raycast;

typedef struct s_wolf
{
	void		*mlx;
	void		*window;
	void		*graphic;
	int			**matrix;
	int			**map;
	int			*data;
	int			**texture;
	int			x;
	int			y;
	int			map_size;
	int			start;
	int			end;
	int			t_h[1];
	int			t_w[1];
	int			dist;
	int			color;
	t_player	player;
	t_raycast	ray;
}				t_wolf;

/* graphic.c */
void	floor_ceiling(t_wolf *maze, int x);
void	insert_texture(t_wolf *maze, int x);
void	xpm_file(t_wolf *maze);

/* init.c */
void	init_player(t_wolf *maze);
void	init_wall(t_wolf *maze);
void	frame_update(t_wolf *maze);

/* map_check.c */
char	*valid_check1(char **graph, char *file, t_wolf *maze);
void	valid_check2(t_wolf *maze, int flag);
int		**get_value(char **graph, t_wolf *maze);

/* movement.c */
int		move_setting(int key, t_wolf *maze);

/* raycast.c */
int		init_window(t_wolf *maze);

/* window.c */
void	print_msg(char *msg);
int		red_cross(t_wolf maze);
void	control_instruction(t_wolf *maze);
void	clear_graph(t_wolf *maze);

#endif
