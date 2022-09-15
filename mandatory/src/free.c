/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:03:14 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/15 15:43:43 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_vars *vars)
{
	size_t	i;
	t_type	type;

	i = 0;
	while (i < vars->col)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	type = back;
	while (type <= enemy)
	{
		mlx_destroy_image(vars->mlx, vars->image_ptr[type]);
		type++;
	}
	mlx_destroy_window(vars->mlx, vars->win);
}

void	free_map_c(t_vars *vars, char **map_c)
{
	size_t	i;

	i = 0;
	while (i < vars->col)
	{
		free(map_c[i]);
		i++;
	}
	free(map_c);
}