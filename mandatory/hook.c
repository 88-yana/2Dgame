/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:50:25 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/14 16:58:35 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	move_player(t_vars *vars, int x, int y);
void	decide_enemy_move(t_vars *vars, int dr);

int	key_hook(int keycode, t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player[X];
	y = vars->player[Y];
	if (keycode == KEY_W)
	{
		move_player(vars, x, y - 1);
		decide_enemy_move(vars, vars->framerate % 4);
	}
	if (keycode == KEY_A)
	{
		move_player(vars, x - 1, y);
		decide_enemy_move(vars, vars->framerate % 4);
	}
	if (keycode == KEY_S)
	{
		move_player(vars, x, y + 1);
		decide_enemy_move(vars, vars->framerate % 4);
	}
	if (keycode == KEY_D)
	{
		move_player(vars, x + 1, y);
		decide_enemy_move(vars, vars->framerate % 4);
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free_map(vars);
		exit(0);
	}
	return (0);
}

int	loop_hook(t_vars *vars)
{
	t_type	type;

	type = road;
	while (type <= enemy)
	{
		draw_image(vars, type);
		type++;
	}
	type = hito0;
	while (type <= hito5)
	{
		if ((t_type) vars->framerate / 9 + hito0 == type)
			vars->map[vars->player[Y]][vars->player[X]] = type;
		type++;
	}
	if (vars->framerate == 54)
		vars->framerate = 0;
	vars->framerate++;
	return (0);
}
