/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:31:39 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/08 11:21:55 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_last_line(t_vars *vars, char **map_c)
{
	if (ft_strlen(map_c[vars->col - 1]) == vars->row)
	{
		if (map_c[vars->col - 1][vars->row - 1] != '\n')
		{
			free_map_c(vars, map_c);
			ft_putendl_fd("Error\nMap is not a rectangle", 2);
			exit(1);
		}
	}
	else if (ft_strlen(map_c[vars->col - 1]) == vars->row - 1)
	{
		if (map_c[vars->col - 1][vars->row - 2] != '1')
		{
			free_map_c(vars, map_c);
			ft_putendl_fd("Error\nMap is not a rectangle", 2);
			exit(1);
		}
	}
	else
	{
		free_map_c(vars, map_c);
		ft_putendl_fd("Error\nMap is not a rectangle", 2);
		exit(1);
	}
}

void	match_condition(int cnt_p, int cnt_c, int cnt_e)
{
	if (cnt_p != 1)
	{
		ft_putendl_fd("Error\nPlayer's start is not one", 2);
		exit(1);
	}
	if (cnt_c == 0)
	{
		ft_putendl_fd("Error\nCollectible is zero", 2);
		exit(1);
	}
	if (cnt_e == 0)
	{
		ft_putendl_fd("Error\nExit is zero", 2);
		exit(1);
	}
}
