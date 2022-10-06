/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:12:33 by kfum              #+#    #+#             */
/*   Updated: 2022/04/06 14:12:33 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
**	Print out messages
*/
void	print_msg(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

/*
** Red cross button on the window left corner
*/
int	red_cross(t_wolf maze)
{
	(void)maze;
	print_msg(EXIT);
	exit(0);
	return (0);
}

/*
** ** Instruction for the controls that show on screen
*/
void	control_instruction(t_wolf *maze)
{
	mlx_string_put(maze->mlx, maze->window, 20, HEIGHT - 70, 0x7B241C0,
		L_R);
	mlx_string_put(maze->mlx, maze->window, 20, HEIGHT - 60, 0x7B241C0, "");
	mlx_string_put(maze->mlx, maze->window, 20, HEIGHT - 50, 0x7B241C0,
		F_B);
	mlx_string_put(maze->mlx, maze->window, 20, HEIGHT - 40, 0x7B241C0, "");
	mlx_string_put(maze->mlx, maze->window, 20, HEIGHT - 30, 0x7B241C0,
		ESC);
}

/*
** Clear the graphic from window
*/
void	clear_graph(t_wolf *maze)
{
	char	*graph;
	int		g;

	graph = mlx_get_data_addr(maze->graphic, &g, &g, &g);
	ft_bzero(graph, 4 * WIDTH * HEIGHT);
}
