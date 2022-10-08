/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:20:34 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/08 15:25:18 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#define WALL '1'
#define ROAD '0'
#define START 'P'
#define ITEM 'C'
#define GOAL 'E'
#define MARK 'M'

void	bfs(char **map, size_t col, size_t row)
{
	if (map[col][row] != WALL && map[col][row] != MARK)
	{
		map[col][row] = MARK;
		bfs(map, col, row + 1);
		bfs(map, col, row - 1);
		bfs(map, col + 1, row);
		bfs(map, col - 1, row);
	}
	else
		return ;
}

static size_t	find_p(t_vars *vars, char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < vars->col)
	{
		j = 0;
		while (j < vars->row - 1)
		{
			if (map[i][j] == START)
				return (i * (vars->row - 1) + j);
			j++;
		}
		i++;
	}
	return (0);
}

static size_t	find_e(t_vars *vars, char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < vars->col)
	{
		j = 0;
		while (j < vars->row - 1)
		{
			if (map[i][j] == GOAL)
				return (i * (vars->row - 1) + j);
			j++;
		}
		i++;
	}
	return (0);
}

char	**copy_map(t_vars *vars, char **map_c)
{
	char	**map;
	size_t	i;
	size_t	j;

	map = malloc(sizeof(char *) * vars->col);
	if (map == NULL)
	{
		perror(NULL);
		exit(1);
	}
	i = 0;
	while (i < vars->col)
	{
		map[i] = malloc(sizeof(char) * (vars->row - 1));
		if (map[i] == NULL)
			free_gnl(map);
		j = 0;
		while (j < vars->row - 1)
		{
			map[i][j] = map_c[i][j];
			j++;
		}
		i++;
	}
	return (map);
}

void	check_path(t_vars *vars, char **map_c)
{
	char	**map;
	size_t	row;
	size_t	goal;

	row = vars->row - 1;
	map = copy_map(vars, map_c);
	goal = find_e(vars, map);
	bfs(map, find_p(vars, map) / row, find_p(vars, map) % row);
	if (map[goal / row][goal % row] == GOAL)
	{
		ft_putendl_fd("Error\nMap has not valid path", 2);
		free_map_c(vars, map);
		exit(1);
	}
	free_map_c(vars, map);
}
