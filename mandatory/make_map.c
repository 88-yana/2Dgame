/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:52:38 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/14 18:31:08 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_enemy(t_vars *vars, size_t i, size_t j)
{
	vars->enemy[X] = j;
	vars->enemy[Y] = i;
	vars->map[i][j] = enemy;
	vars->is_enemy_existing = 1;
}

static void	put_player(t_vars *vars, size_t i, size_t j)
{
	vars->player[X] = j;
	vars->player[Y] = i;
	vars->map[i][j] = hito0;
}

static void	handle_row(t_vars *vars, size_t i, char **map_c)
{
	size_t	j;

	j = 0;
	while (j < vars->row)
	{
		if (map_c[i][j] == '0')
		{
			vars->map[i][j] = road;
			if (vars->is_enemy_existing == 0)
				put_enemy(vars, i, j);
		}
		if (map_c[i][j] == '1')
			vars->map[i][j] = wall;
		if (map_c[i][j] == 'P')
			put_player(vars, i, j);
		if (map_c[i][j] == 'C')
		{
			vars->map[i][j] = item;
			vars->sum_item++;
		}
		if (map_c[i][j] == 'E')
			vars->map[i][j] = closed_door;
		j++;
	}
}

void	make_map(t_vars *vars, char **map_c)
{
	size_t	i;

	vars->map = malloc(sizeof(t_type *) * vars->col);
	i = 0;
	while (i < vars->col)
	{
		vars->map[i] = malloc(sizeof(t_type) * vars->row);
		handle_row(vars, i, map_c);
		i++;
	}
	free_map_c(vars, map_c);
}
