// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/08/29 19:13:02 by hyanagim          #+#    #+#             */
// /*   Updated: 2022/08/31 21:40:00 by hyanagim         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	char	**map_c;
	t_vars	vars;

	// 引数名のエラー処理
	check_arg(argc, argv);
	// マップ読み込み
	map_c = read_file(&vars, argv[1]);
	for (size_t i = 0; i < vars.col; i++)
		printf("%s", map_c[i]);
	printf("\n");
	// マップエラー処理,マップの縦横を測る
	check_map(&vars, map_c);
	//varsの値を初期化
	init_vars(&vars);
	// マップを二次元配列に突っ込む
	make_map(&vars, map_c);
	
	
	for (size_t i = 0; i < vars.col; i++)
	{
		for (size_t j = 0; j < vars.row; j++)
		{
			printf("%d'", vars.map[i][j]);
		}
		printf("\n");
	}
	// windowを開始
	init_window(&vars);
	// 背景白に
	draw_back_white(&vars);
	// マップに合わせて表示
	display_map(&vars);
	return (0);
}
