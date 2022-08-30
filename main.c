/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:13:02 by hyanagim          #+#    #+#             */
/*   Updated: 2022/08/30 18:01:30 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int rgb_to_int(int r, int g, int b)
{
	int color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

int main()
{
	void *mlx;//スクリーン接続識別子
	void *mlx_win;//ウィンドウ識別子
	int i;
	int j;
	int width = 1000; //ウィンドウのサイズ
	int height = 1000;
	int w = 0;
	int h = 0;
	char *image = "./tree.xpm";
	char *image1 = "./cherry.xpm";
	char *image2 = "./door.xpm";
	void *image_ptr;
	void *image_ptr1;
	void *image_ptr2;
	mlx = mlx_init();//fileopenの時のfd的な？
	mlx_win = mlx_new_window(mlx, width, height,"so_long");
	// mlx_win = mlx_new_window(スクリーン識別子, width, height,"test");
	//座標は左上が原点、矢印はx軸が右、y軸が下向きになる
	//でも与えられる図形の座標は一般的な向きの座標のためあとで座標変換が必要となる
	   i= 0;
	int color = rgb_to_int(100, 40, 0);
	while (i < width)
	{
			j = 0;
			while (j < height)
			{
				if(j % 3 == 0)
					mlx_pixel_put(mlx, mlx_win, i, j, rgb_to_int(60, 240, 100));
				if(j % 3 == 1)
					mlx_pixel_put(mlx, mlx_win, i, j, rgb_to_int(60, 200, 100));
				if (j % 3 == 2)
					mlx_pixel_put(mlx, mlx_win, i, j, rgb_to_int(60, 180, 100));
					j++;
			}
			i++;
	}
	image_ptr = mlx_xpm_file_to_image(mlx, image, &w, &h);
	image_ptr1 = mlx_xpm_file_to_image(mlx, image1, &w, &h);
	image_ptr2 = mlx_xpm_file_to_image(mlx, image2, &w, &h);
	for (int i = 0; i < 3; i++)
	{
		mlx_put_image_to_window(mlx, mlx_win, image_ptr, 100 * i, 0);
	}
	
	mlx_put_image_to_window(mlx, mlx_win, image_ptr1, 100, 100);
	mlx_put_image_to_window(mlx, mlx_win, image_ptr2, 200, 200);
	mlx_loop(mlx);//無限ループを作り、その間ウィンドウを表示させ続ける
	//最初のうちはcntl+Cで強制終了すればおk
	//クリックした時に終了させるなどのプログラムはゆくゆく書く必要がある
	return (1);
}
