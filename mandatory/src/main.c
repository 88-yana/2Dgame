/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:13:02 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/15 15:44:00 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	char	**map_c;
	t_vars	vars;

	check_arg(argc, argv);
	map_c = read_file(&vars, argv[1]);
	check_map(&vars, map_c);
	init_vars(&vars);
	make_map(&vars, map_c);
	init_window(&vars);
	draw_back_white(&vars);
	display_map(&vars);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	char	**map_c;
// 	t_vars	vars;

// 	check_arg(argc, argv);
// 	map_c = read_file(&vars, argv[1]);
// 	for (size_t i = 0; i < vars.col; i++)
// 		printf("%s", map_c[i]);
// 	printf("\n");
// 	check_map(&vars, map_c);
// 	init_vars(&vars);
// 	make_map(&vars, map_c);
// 	for (size_t i = 0; i < vars.col; i++)
// 	{
// 		for (size_t j = 0; j < vars.row; j++)
// 		{
// 			printf("%d'", vars.map[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	init_window(&vars);
// 	draw_back_white(&vars);
// 	display_map(&vars);
// 	return (0);
// }