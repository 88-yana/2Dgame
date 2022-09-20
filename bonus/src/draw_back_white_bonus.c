/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_back_white_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:08:48 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/21 07:50:11 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	rgb_to_int(int r, int g, int b)
{
	int	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

void	draw_back_white(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < vars->col * 100)
	{
		j = 0;
		while (j < vars->row * 100)
		{
			mlx_pixel_put(vars->mlx, vars->win, j, i,
				rgb_to_int(255, 255, 255));
			j++;
		}
		i++;
	}
}
