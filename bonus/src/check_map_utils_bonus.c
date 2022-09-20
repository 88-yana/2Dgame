/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:31:39 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/21 07:50:02 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_last_line(t_vars *vars, char **map_c)
{
	if (ft_strlen(map_c[vars->col - 1]) == vars->row)
	{
		if (map_c[vars->col - 1][vars->row - 1] != '\n')
		{
			free_map_c(vars, map_c);
			write(2, "Error\nMap is not a rectangle", 29);
			exit(1);
		}
	}
	else if (ft_strlen(map_c[vars->col - 1]) == vars->row - 1)
	{
		if (map_c[vars->col - 1][vars->row - 2] != '1')
		{
			free_map_c(vars, map_c);
			write(2, "Error\nMap is not a rectangle", 29);
			exit(1);
		}
	}
	else
	{
		free_map_c(vars, map_c);
		write(2, "Error\nMap is not a rectangle", 29);
		exit(1);
	}
}

void	match_condition(int cnt_p, int cnt_c, int cnt_e)
{
	if (cnt_p != 1)
	{
		write(2, "Error\nPlayer's start is not one", 32);
		exit(1);
	}
	if (cnt_c == 0)
	{
		write(2, "Error\nCollectible is zero", 26);
		exit(1);
	}
	if (cnt_e == 0)
	{
		write(2, "Error\nExit is zero", 19);
		exit(1);
	}
}
