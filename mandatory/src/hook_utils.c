/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:36:59 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/08 20:22:48 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	if (vars->map[y][x] != wall && vars->map[y][x] != closed_door)
	{
		vars->map[vars->player[Y]][vars->player[X]] = road;
		vars->player[X] = x;
		vars->player[Y] = y;
		vars->steps++;
		ft_printf("steps : %d\n", vars->steps);
		change_map(vars, x, y);
	}
	return ;
}
