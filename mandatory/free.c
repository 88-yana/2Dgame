/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:03:14 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/14 17:14:34 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < vars->col)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
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
