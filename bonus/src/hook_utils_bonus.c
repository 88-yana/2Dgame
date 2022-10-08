/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:36:59 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/08 20:21:49 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	decide_enemy_move(t_vars *vars, int dr);

static void	move_enemy(t_vars *vars, int x, int y, int dr)
{
	if (vars->map[y][x] != wall && vars->map[y][x] != closed_door
	&& vars->map[y][x] != item && vars->map[y][x] != open_door)
	{
		vars->map[vars->enemy[Y]][vars->enemy[X]] = road;
		vars->enemy[X] = x;
		vars->enemy[Y] = y;
		vars->map[y][x] = enemy;
		if (vars->enemy[X] == vars->player[X]
			&& vars->enemy[Y] == vars->player[Y])
		{
			free_map(vars);
			ft_printf("failure, enemy catched you\n");
			exit (0);
		}
		return ;
	}
	decide_enemy_move(vars, (dr + 1) % 4);
	return ;
}

void	decide_enemy_move(t_vars *vars, int dr)
{
	int				x;
	int				y;
	static size_t	surrounded = 1;

	x = vars->enemy[X];
	y = vars->enemy[Y];
	if (surrounded % 462 == 0)
	{
		surrounded = 1;
		return ;
	}
	if (dr == 0)
		move_enemy(vars, x, y - 1, dr);
	surrounded *= 2;
	if (dr == 1)
		move_enemy(vars, x - 1, y, dr);
	surrounded *= 3;
	if (dr == 2)
		move_enemy(vars, x, y + 1, dr);
	surrounded *= 7;
	if (dr == 3)
		move_enemy(vars, x + 1, y, dr);
	surrounded *= 11;
	return ;
}

void	change_closed_to_open(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < vars->col)
	{
		j = 0;
		while (j < vars->row)
		{
			if (vars->map[i][j] == closed_door)
				vars->map[i][j] = open_door;
			j++;
		}
		i++;
	}
}

static void	change_map(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == item)
	{
		vars->now_sum_item++;
		if (vars->now_sum_item == vars->sum_item)
			change_closed_to_open(vars);
	}
	else if (vars->map[y][x] == open_door)
	{
		free_map(vars);
		ft_printf("success, steps : %d\n", vars->steps);
		exit(0);
	}
	return ;
}

void	move_player(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] != wall && vars->map[y][x] != closed_door
	&& vars->map[y][x] != enemy)
	{
		vars->map[vars->player[Y]][vars->player[X]] = road;
		vars->player[X] = x;
		vars->player[Y] = y;
		vars->steps++;
		change_map(vars, x, y);
	}
	return ;
}
