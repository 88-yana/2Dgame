/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:46:39 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/14 17:51:28 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	cnt_sum_nl(t_vars *vars, char *file_name)
{
	int		fd;
	size_t	sum_nl;

	sum_nl = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror(file_name);
		exit(1);
	}
	while (get_next_line(fd))
		sum_nl++;
	vars->col = sum_nl;
	close(fd);
	return (sum_nl);
}

char	**read_file(t_vars *vars, char *file_name)
{
	int		fd;
	size_t	i;
	size_t	sum_nl;
	char	**map_c;

	sum_nl = cnt_sum_nl(vars, file_name);
	map_c = malloc(sizeof(char *) * (sum_nl + 1));
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror(file_name);
		exit(1);
	}
	i = 0;
	while (i < sum_nl)
	{
		map_c[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map_c);
}
