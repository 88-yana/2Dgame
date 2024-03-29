/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:05:36 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/15 15:43:57 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_vars(t_vars *vars)
{
	vars->row--;
	vars->framerate = 0;
	vars->sum_item = 0;
	vars->now_sum_item = 0;
	vars->steps = 0;
	vars->is_enemy_existing = 0;
}

void	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx,
			100 * vars->row, 100 * vars->col, "so_long");
}
