/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:19:01 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/14 16:59:39 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_vars *vars, t_type type)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < vars->col)
	{
		j = 0;
		while (j < vars->row)
		{
			if (type == back || vars->map[i][j] == type)
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->image_ptr[type], 100 * j, 100 * i);
			}
			j++;
		}
		i++;
	}
}

static void	make_image_ptr(t_vars *vars, t_type type, char *file_name)
{
	int	w;
	int	h;

	w = 100;
	h = 100;
	vars->image_ptr[type] = mlx_xpm_file_to_image(vars->mlx, file_name, &w, &h);
}

static void	make_image(t_vars *vars)
{
	make_image_ptr(vars, back, "image_xpm/lemon.xpm");
	make_image_ptr(vars, wall, "image_xpm/tree.xpm");
	make_image_ptr(vars, road, "image_xpm/lemon.xpm");
	make_image_ptr(vars, item, "image_xpm/cherry.xpm");
	make_image_ptr(vars, closed_door, "image_xpm/closed_door.xpm");
	make_image_ptr(vars, open_door, "image_xpm/door.xpm");
	make_image_ptr(vars, hito0, "image_xpm/hito00.xpm");
	make_image_ptr(vars, hito1, "image_xpm/hito01.xpm");
	make_image_ptr(vars, hito2, "image_xpm/hito02.xpm");
	make_image_ptr(vars, hito3, "image_xpm/hito03.xpm");
	make_image_ptr(vars, hito4, "image_xpm/hito04.xpm");
	make_image_ptr(vars, hito5, "image_xpm/hito05.xpm");
	make_image_ptr(vars, enemy, "image_xpm/enemy.xpm");
}

void	display_map(t_vars *vars)
{
	make_image(vars);
	draw_image(vars, back);
	draw_image(vars, wall);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop_hook (vars->mlx, loop_hook, vars);
	mlx_loop(vars->mlx);
}
