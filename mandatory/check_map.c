/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:20:16 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/14 15:53:54 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_rectangle(t_vars *vars, char **map_c)
{
	size_t	i;

	i = 0;
	vars->row = ft_strlen(map_c[0]);
	while (i < vars->col)
	{
		if (ft_strlen(map_c[i]) != vars->row)
		{
			if (i == vars->col - 1 && ft_strlen(map_c[i]) + 1 == vars->row)
			{
				if (map_c[i][vars->row - 2] == '1')
				{
					i++;
					continue ;
				}
			}
			free_map_c(vars, map_c);
			write(2, "Error\nMap is not a rectangle", 29);
			exit(1);
		}
		i++;
	}
	if (map_c[vars->col - 1][vars->row - 1] == '1')
	{
		free_map_c(vars, map_c);
		write(2, "Error\nMap is not a rectangle", 29);
		exit(1);
	}
}

static void	is_surrounded(t_vars *vars, char **map_c)
{
	size_t	i;

	i = 0;
	while (i < vars->row - 1)
	{
		if (map_c[0][i] == map_c[vars->col - 1][i] && map_c[0][i] == '1')
		{
			i++;
			continue ;
		}
		write(2, "Error\nMap is not surrounded", 28);
		exit(1);
	}
	i = 0;
	while (i < vars->col)
	{
		if (map_c[i][0] == map_c[i][vars->row - 2] && map_c[i][0] == '1')
		{
			i++;
			continue ;
		}
		write(2, "Error\nMap is not surrounded", 28);
		exit(1);
	}
}

static void	match_condition(int cnt_p, int cnt_c, int cnt_e)
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

static void	check_components(t_vars *vars, char **map_c)
{
	size_t	i;
	size_t	j;
	int		cnt[3];

	i = 0;
	cnt[0] = 0;
	cnt[1] = 0;
	cnt[2] = 0;
	while (i < vars->col)
	{
		j = 0;
		while (j < vars->row - 1)
		{
			if (map_c[i][j] == 'P')
				cnt[0]++;
			if (map_c[i][j] == 'C')
				cnt[1]++;
			if (map_c[i][j] == 'E')
				cnt[2]++;
			j++;
		}
		i++;
	}
	match_condition(cnt[0], cnt[1], cnt[2]);
}

void	check_map(t_vars *vars, char **map_c)
{
	if (vars->col == 0)
	{
		write(2, "Error\nfirst line in file is empty", 34);
		exit(1);
	}
	if (map_c[0][0] != '1')
	{
		write(2, "Error\nFirst line is invalid", 28);
		exit(1);
	}
	is_rectangle(vars, map_c);
	is_surrounded(vars, map_c);
	check_components(vars, map_c);
}
