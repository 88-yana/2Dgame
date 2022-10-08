/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:13:02 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/08 14:19:35 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
