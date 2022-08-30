/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:13:02 by hyanagim          #+#    #+#             */
/*   Updated: 2022/08/30 15:45:00 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
int main()
{
	void *mlx;//スクリーン接続識別子
	void *mlx_win;//ウィンドウ識別子
	int i;
	int j;
	int width = 1000; //ウィンドウのサイズ
	int height = 1000;
	int w = 500;
	int h = 500;
	char *image = "./stop.xpm";
	void *image_ptr;
	mlx = mlx_init();//fileopenの時のfd的な？
	mlx_win = mlx_new_window(mlx, width, height,"so_long");
	// mlx_win = mlx_new_window(スクリーン識別子, width, height,"test");
	//座標は左上が原点、矢印はx軸が右、y軸が下向きになる
	//でも与えられる図形の座標は一般的な向きの座標のためあとで座標変換が必要となる
	   i= 0;
	// while (i < width)
	// {
	// 		j = 0;
	// 		while (j < height)
	// 		{
	// 				mlx_pixel_put(mlx, mlx_win, i, j, 127);
	// 				j++;
	// 		}
	// 		i++;
	// }
	image_ptr = mlx_xpm_file_to_image(mlx, image, &w, &h);
	mlx_put_image_to_window(mlx, mlx_win, image_ptr, 0, 0);
	mlx_loop(mlx);//無限ループを作り、その間ウィンドウを表示させ続ける
	//最初のうちはcntl+Cで強制終了すればおk
	//クリックした時に終了させるなどのプログラムはゆくゆく書く必要がある
	return (1);
}
