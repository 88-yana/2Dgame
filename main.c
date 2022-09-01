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

// #include "mlx.h"

int rgb_to_int(int r, int g, int b)
{
	int color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

// // int main(int argc, char **argv)
// // {
// // 	void *mlx;//スクリーン接続識別子
// // 	void *mlx_win;//ウィンドウ識別子
// // 	int i;
// // 	int j;
// // 	int width = 1000; //ウィンドウのサイズ
// // 	int height = 1000;
// // 	int w = 0;
// // 	int h = 0;
// // 	char *image = "./tree.xpm";
// // 	char *image1 = "./cherry.xpm";
// // 	char *image2 = "./door.xpm";
// // 	char *image3 = "./lemon.xpm";
// // 	void *image_ptr;
// // 	void *image_ptr1;
// // 	void *image_ptr2;
// // 	void *image_ptr3;
// // 	mlx = mlx_init();//fileopenの時のfd的な？
// // 	mlx_win = mlx_new_window(mlx, width, height,"so_long");
// // 	// mlx_win = mlx_new_window(スクリーン識別子, width, height,"test");
// // 	//座標は左上が原点、矢印はx軸が右、y軸が下向きになる
// // 	//でも与えられる図形の座標は一般的な向きの座標のためあとで座標変換が必要となる
// // 	   i= 0;
// // 	int color = rgb_to_int(100, 40, 0);
// // 	while (i < width)
// // 	{
// // 			j = 0;
// // 			while (j < height)
// // 			{
// // 				// if(j % 3 == 0)
// // 				// 	mlx_pixel_put(mlx, mlx_win, i, j, rgb_to_int(60, 240, 100));
// // 				// if(j % 3 == 1)
// // 				// 	mlx_pixel_put(mlx, mlx_win, i, j, rgb_to_int(60, 200, 100));
// // 				// if (j % 3 == 2)
// // 				// 	mlx_pixel_put(mlx, mlx_win, i, j, rgb_to_int(60, 180, 100));
// // 				mlx_pixel_put(mlx, mlx_win, i, j, rgb_to_int(255, 255, 255));
// // 					j++;
// // 			}
// // 			i++;
// // 	}
// // 	image_ptr = mlx_xpm_file_to_image(mlx, image, &w, &h);
// // 	image_ptr1 = mlx_xpm_file_to_image(mlx, image1, &w, &h);
// // 	image_ptr2 = mlx_xpm_file_to_image(mlx, image2, &w, &h);
// // 	image_ptr3 = mlx_xpm_file_to_image(mlx, image3, &w, &h);
// // 	for (int i = 0; i < 10; i++)
// // 	{
// // 		for (int j = 0; j < 10; j++)
// // 		{
// // 			mlx_put_image_to_window(mlx, mlx_win, image_ptr3, 100 * i, 100 * j);
// // 		}
// // 	}
	
// // 	for (int i = 0; i < 3; i++)
// // 	{
// // 		mlx_put_image_to_window(mlx, mlx_win, image_ptr, 100 * i, 0);
// // 	}
	
// // 	mlx_put_image_to_window(mlx, mlx_win, image_ptr1, 100, 100);
// // 	mlx_put_image_to_window(mlx, mlx_win, image_ptr2, 200, 200);
// // 	mlx_loop(mlx);//無限ループを作り、その間ウィンドウを表示させ続ける
// // 	// void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param);
// // 	//最初のうちはcntl+Cで強制終了すればおk
// // 	//クリックした時に終了させるなどのプログラムはゆくゆく書く必要がある
// // 	return (1);
// // }


// // #include <mlx.h>
// // #include <stdio.h>

// // typedef struct s_vars {
// // 	void	*mlx;
// // 	void	*win;
// // }	t_vars;

// // int	key_hook(int keycode, t_vars *vars)
// // {
// // 	if (keycode == 2)
// // 		printf("Hello from key_hook!\n");
// // 	else
// // 		printf("else!\n");

// // 	return (0);
// // }

// // int	main(void)
// // {
// // 	t_vars	vars;

// // 	vars.mlx = mlx_init();
// // 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// // 	mlx_key_hook(vars.win, key_hook, &vars);
// // 	mlx_loop(vars.mlx);
// // }

// # include	<unistd.h>
// # include	<stdlib.h>
// # include	<stdio.h>
// # include	<fcntl.h>

// int	getdescriptor(char *str)
// {
// 	int	num;

// 	num = open(str, O_RDONLY);
// 	if (num == -1)
// 	{
// 		// putcaution();
// 		return (-1);
// 	}
// 	else
// 		return (num);
// }

// char	*get_mapline(char *mapline, size_t size)
// {
// 	mapline = malloc(sizeof(char) * (size + 1));
// 	if (mapline == NULL)
// 	{
// 		// putcaution();
// 		return (NULL);
// 	}
// 	return (mapline);
// }

// size_t	countfile(int fd)
// {
// 	char	c;
// 	size_t	size;

// 	size = 0;
// 	while (read(fd, &c, 1) != 0)
// 		size++;
// 	close(fd);
// 	return (size);
// }

// char	*readfile(char *str)
// {
// 	int		fd;
// 	size_t	i;
// 	size_t	size;
// 	char	*mapline;

// 	mapline = NULL;
// 	fd = getdescriptor(str);
// 	if (fd == -1)
// 		return (NULL);
// 	size = countfile(fd);
// 	mapline = get_mapline(mapline, size);
// 	if (mapline == NULL)
// 		return (NULL);
// 	fd = getdescriptor(str);
// 	i = 0;
// 	while (read(fd, &mapline[i], 1) != 0)
// 		i++;
// 	mapline[size] = '\0';
// 	close(fd);
// 	return (mapline);
// }

// // int	checkmap(char *mapline, char eof[])
// // {
// // 	if (mapline == NULL)
// // 		return (1);
// // 	if (extracteof(mapline, eof) == NULL)
// // 		return (1);
// // 	if (countrow(mapline) == 0 || countcol(mapline) == 0)
// // 	{
// // 		putcaution();
// // 		return (1);
// // 	}
// // 	return (0);
// // }

// int	main(int argc, char *argv[])
// {
// 	char	*mapline;
// 	int		row_col[2]; //typedef する。
// 	int		i;
// 	// char	eof[4];

// 	i = 0;
// 	// if (argc == 1)
// 	// {
// 	// 	mapline = readstdin();
// 	// 	i--;
// 	// }
// 		if (argc > 1)
// 			mapline = readfile(argv[1]);
// 		// if (checkmap(mapline, eof) == 1)
// 		// 	continue ;
// 		// row_col[0] = countrow(mapline);
// 		// row_col[1] = countcol(mapline);
// 		// if (map_gen(mapline, row_col, eof, argv[i]))
// 		// 	continue ;
// 	while (mapline[i] != '\0')
// 		printf("%c", mapline[i++]);
// 	free(mapline);
// 	return (0);
// }



#include "mlx.h"
#include <stdio.h>
#define TYPE 6

// // typedef struct s_map {
// // 	int		player;
// // 	int		door;
// // }	t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	//playerをintで持つかどうか考えている。
	int		col;
	int		row;
	char	*image[TYPE];
	char	*image_ptr[TYPE];
	int		kari;
}	t_vars;

typedef enum e_num {
	back,
	wall,
	item,
	player,
	closed_door,
	open_door,
}	t_type;

// void	generate_map(char *mapline, t_vars *vars)
// {
	
// }

// void	make_map(char *mapline, t_vars *vars)
// {
// 	vars->col = countcol(mapline);
// 	vars->row = countrow(mapline);
// 	// 	壁とアイテムと扉とプレーヤーのマップを分ける？
// 	generate_map(mapline, vars);
// }

void	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 100 * vars->row, 100 * vars->col,"so_long");
}



// void	draw_back(t_vars *vars, void *image_ptr)
// {
// 	int i;
// 	int j;
// 	i = 0;
// 	j = 0;
// 	while (i < vars->col)
// 	{
// 		while (j < vars->row)
// 		{
// 			mlx_put_image_to_window(vars->mlx, vars->win, image_ptr, 100 * i, 100 * j);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	draw_wall(t_vars *vars, void *image_ptr)
// {
// 	int i;
// 	int j;
// 	i = 0;
// 	j = 0;
// 	while (i < vars->col)
// 	{
// 		while (j < vars->row)
// 		{
// 			if (vars->map[i][j] == '1')
// 				mlx_put_image_to_window(vars->mlx, vars->win, image_ptr, 100 * i, 100 * j);
// 			j++;
// 		}
// 		i++;
// 	}
// }

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 2)
	{
		printf("Hello from key_hook!\n");
		(vars->kari)--; 
		printf("%d\n", vars->kari);
	}
	else
		printf("else!\n");

	return (0);
}

int	loop_hook(t_vars *vars)
{
	printf("%d\n", vars->kari);
	for (int i = 0; i < vars->col * 100; i++)
	{
		for (int j = 0; j < vars->row * 100; j++)
		{
			mlx_pixel_put(vars->mlx, vars->win, i, j, rgb_to_int(vars->kari, vars->kari, vars->kari));
		}
		
	}
	return (0);
	// printf("%d\n", vars->col);
}

// void	display_map(t_vars *vars)
// {

// 	//画像のポインタを作る
// 	make_image(&vars);
// 	//	背景を表示
// 	draw_back(vars, vars->image_ptr[back]);
// 	//	壁を表示
// 	draw_wall(vars, vars->image_ptr[wall]);
	
// 	// while (扉が開いた状態（アイテムを全部とった状態）かつ　扉に行った場合　に終了)
// 		// 	アイテムと扉とプレーヤーは毎ターン表示してもいいかもしれない
// 		// 	キーボード入力を受け取る
// 		// 	playerが進めるか（壁でないか）チェックして，進め，表示
// 	mlx_key_hook(vars->win, key_hook, &vars);
// 	mlx_loop_hook (vars->mlx, loop_hook, &vars);
// 	// mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );
// 	mlx_loop(vars->mlx);
// }

// int main(int argc, char **argv)
// {
// 	char	*mapline;
// 	t_vars	vars;

// 	// 引数名のエラー処理
// 	check_arg(argc, argv);
// 	// マップ読み込み
// 	mapline = read_file(argv[1]);
// 	// マップエラー処理
// 	check_map(mapline);
// 	// マップの縦横を測る
// 	// マップを二次元配列に突っ込む
// 	make_map(mapline, &vars);

// 	//windowを開始
// 	init_window(&vars);
// 	// マップに合わせて表示
// 	display_map(&vars);

// 	handle_event(&vars);

// 	return (0);
// }

int kari (t_vars *vars)
{
	printf("%d\n", vars->kari);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop_hook(vars->mlx, loop_hook, vars);
	mlx_loop(vars->mlx);
	// mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );
	return (0);
}

int	main(void)
{
	t_vars	vars;
	vars.col = 3;
	vars.row = 3;
	vars.kari = 200;
	init_window(&vars);
	for (int i = 0; i < vars.col * 100; i++)
	{
		for (int j = 0; j < vars.row * 100; j++)
		{
			mlx_pixel_put(vars.mlx, vars.win, i, j, rgb_to_int(vars.kari, vars.kari, vars.kari));
		}
		
	}
	printf("LINE == %d, FILE == %s :", __LINE__, __FILE__);
	printf("%d\n", vars.kari);
	kari(&vars);
	return (0);
}

// #include <mlx.h>
// #include <stdio.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	key_hook(int keycode, t_vars *vars, int *a)
// {
// 	if (keycode == 2)
// 		printf("yeah\n");
// 	else
// 		printf("Hello from key_hook!\n");
// 	printf("both\n");
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;
// 	int a = 0;
// 	int keycode;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	printf("a = %d\n", a);
// 	int (*hook)(int, t_vars *, int);
// 	hook = key_hook(0, &vars, &a);
// 	a = mlx_key_hook(vars.win, hook, &vars);
// 	printf("a = %d\n", a);
// 	mlx_loop(vars.mlx);
// }