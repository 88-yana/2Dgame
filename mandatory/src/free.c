/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:03:14 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/21 07:38:39 by hyanagim         ###   ########.fr       */
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
		vars->map[i] = NULL;
		i++;
	}
	free(vars->map);
	vars->map = NULL;
	type = back;
	while (type <= hito5)
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
