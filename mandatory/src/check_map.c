/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:20:16 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/21 07:31:00 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_last_line(t_vars *vars, char **map_c);
void	match_condition(int cnt_p, int cnt_c, int cnt_e);

static void	is_rectangle(t_vars *vars, char **map_c)
{
	size_t	i;

	i = 0;
	vars->row = ft_strlen(map_c[0]);
	while (i < vars->col - 1)
	{
		if (ft_strlen(map_c[i]) != vars->row)
		{
			free_map_c(vars, map_c);
			write(2, "Error\nMap is not a rectangle", 29);
			exit(1);
		}
		i++;
	}
	check_last_line(vars, map_c);
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
