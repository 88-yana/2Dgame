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
	// char *image = "./tree.xpm";
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
	// image_ptr = mlx_xpm_file_to_image(mlx, image, &w, &h);
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

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"
#include <fcntl.h> //O_RDONLY

#include "mlx.h"

#include <stdio.h>
#define TYPE 7
#define X 0
#define Y 1
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53

// // typedef struct s_map {
// // 	int		player;
// // 	int		door;
// // }	t_map;

typedef enum e_num {
	road,
	back,
	wall,
	item,
	player,
	closed_door,
	open_door,
	hito0,
	hito1,
	hito2,
	hito3,
	hito4,
	hito5,
}	t_type;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_type	**map;
	//playerをintで持つかどうか考えている。
	int		player[2];
	int		col;
	int		row;
	int		door[2]; //door は　ひとつとは限らないので，マップ全体で，closedからopen
	int		now_sum_item;
	int		sum_item;
	int		steps;
	char	*image[TYPE + 7];
	char	*image_ptr[TYPE + 7];
	int		framerate;
}	t_vars;

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

void	check_arg(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(2, "Error\nneed file name\n", 22);
		exit(1);
	}
	if (ft_strcmp(argv[1], ".ber") == 0)
	{
		write(2, "Error\nFile name is invalid\n", 28);
		exit(1);
	}
	if (ft_strchr(argv[1], '.') != ft_strrchr(argv[1], '.'))
	{
		write(2, "Error\nFile name is invalid\n", 28);
		exit(1);
	}
	i = 0;
	while(*(argv[1] + i) != '.')
		i++;
	if (ft_strcmp(argv[1] + i, ".ber") != 0)
	{
		write(2, "Error\nEnd of file name needs to be '.bar'\n", 43);
		exit(1);
	}
}

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
	vars->win = mlx_new_window(vars->mlx, 100 * vars->row, 100 * vars->col, "so_long");
}

void	draw_image(t_vars *vars, t_type type)
{
	int i;
	int j;

	i = 0;
	while (i < vars->col)
	{
		j = 0;
		while (j < vars->row)
		{
			if (type == back || vars->map[i][j] == type)
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->image_ptr[type], 100 * j, 100 * i);
			}
			j++;
		}
		i++;
	}
}

// void	draw_map(t_vars *vars, t_type type)
// {
// 	int i;
// 	int j;
// 	i = 0;
// 	j = 0;
// 	while (i < vars->col)
// 	{
// 		while (j < vars->row)
// 		{
// 			if (type == back || vars->map[i][j] == type)
// 				mlx_put_image_to_window(vars->mlx, vars->win, 
// 					vars->image_ptr[type], 100 * i, 100 * j);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	chage_map(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == item)
	{
		vars->now_sum_item++;
		if (vars->now_sum_item == vars->sum_item)
			vars->map[vars->door[Y]][vars->door[X]] = open_door;
	}
	else if (vars->map[y][x] == open_door)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_printf("success, steps : %d", vars->steps);
	}
	vars->map[y][x] = player;
	return ;
}

void	move_player(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] != wall && vars->map[y][x] != closed_door)
	{
		vars->map[vars->player[Y]][vars->player[X]] = road;
		vars->player[X] = x;
		vars->player[Y] = y;
		vars->steps++;
		chage_map(vars, x, y);
	}
	return ;
}

void	make_image_ptr(t_vars *vars, t_type type, char *file_name)
{
	int w;
	int h;

	w = 100;
	h = 100;
	vars->image[type] = file_name;
	vars->image_ptr[type] = mlx_xpm_file_to_image(vars->mlx, vars->image[type], &w, &h);
}

void make_image(t_vars *vars)
{
	make_image_ptr(vars, back, "image_xpm/lemon.xpm");
	make_image_ptr(vars, wall, "image_xpm/tree.xpm");
	make_image_ptr(vars, item, "image_xpm/cherry.xpm");
	// make_image_ptr(vars, player, "image_xpm/door.xpm");
	make_image_ptr(vars, closed_door, "image_xpm/door.xpm");
	make_image_ptr(vars, open_door, "image_xpm/door.xpm");
	make_image_ptr(vars, hito0, "image_xpm/hito00.xpm");
	make_image_ptr(vars, hito1, "image_xpm/hito01.xpm");
	make_image_ptr(vars, hito2, "image_xpm/hito02.xpm");
	make_image_ptr(vars, hito3, "image_xpm/hito03.xpm");
	make_image_ptr(vars, hito4, "image_xpm/hito04.xpm");
	make_image_ptr(vars, hito5, "image_xpm/hito05.xpm");
}

int	key_hook(int keycode, t_vars *vars)
{
	int x;
	int y;

	x = vars->player[X];
	y = vars->player[Y];
	if (keycode == KEY_W)
		move_player(vars, x, y - 1);
	if (keycode == KEY_A)
		move_player(vars, x - 1, y);
	if (keycode == KEY_S)
		move_player(vars, x, y + 1);
	if (keycode == KEY_D)
		move_player(vars, x + 1, y);
	if (keycode == KEY_ESC)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	loop_hook(t_vars *vars)
{

	//map表示
	draw_image(vars, back);
	draw_image(vars, wall);
	draw_image(vars, item);
	draw_image(vars, hito0);
	draw_image(vars, hito1);
	draw_image(vars, hito2);
	draw_image(vars, hito3);
	draw_image(vars, hito4);
	draw_image(vars, hito5);
	draw_image(vars, closed_door);
	if (vars->framerate / 9 == 0)
		vars->map[vars->player[Y]][vars->player[X]] = hito0;
	if (vars->framerate / 9 == 1)
		vars->map[vars->player[Y]][vars->player[X]] = hito1;
	if (vars->framerate / 9 == 2)
		vars->map[vars->player[Y]][vars->player[X]] = hito2;
	if (vars->framerate / 9 == 3)
		vars->map[vars->player[Y]][vars->player[X]] = hito3;
	if (vars->framerate / 9 == 4)
		vars->map[vars->player[Y]][vars->player[X]] = hito4;
	if (vars->framerate / 9 == 5)
		vars->map[vars->player[Y]][vars->player[X]] = hito5;
	if (vars->framerate ==  54)
		vars->framerate = 0;
	vars->framerate++;
	// printf("%d\n", vars->framerate);
	draw_image(vars, open_door);
	return (0);
}

void	display_map(t_vars *vars)
{

	//画像のポインタを作る
	make_image(vars);
	//	背景を表示
	draw_image(vars, back);
	//	壁を表示
	draw_image(vars, wall);
	
	// while (扉が開いた状態（アイテムを全部とった状態）かつ　扉に行った場合　に終了)
		// 	アイテムと扉とプレーヤーは毎ターン表示してもいいかもしれない
		// 	キーボード入力を受け取る
		// 	playerが進めるか（壁でないか）チェックして，進め，表示
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop_hook (vars->mlx, loop_hook, vars);
	// mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param);
	mlx_loop(vars->mlx);
}





char	**read_file(t_vars *vars, char* file_name)
{
	int fd;
	int i;
	int sum_nl;
	char **map_c;

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

void free_map_c(t_vars *vars, char **map_c)
{
	int i;

	i = 0;
	while (i < vars->col)
	{
		free(map_c[i]);
		i++;
	}
	free(map_c);
}

void is_rectangle(t_vars *vars, char **map_c)
{
	int i;

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
			write(2, "Error\nMap is not a rectangle", 29);
			free_map_c(vars, map_c);
			exit(1);
		}
		i++;
	}
	if (map_c[vars->col - 1][vars->row - 1] == '1')
	{
		write(2, "Error\nMap is not a rectangle", 29);
		free_map_c(vars, map_c);
		exit(1);
	}
}

void is_surrounded(t_vars *vars, char **map_c)
{
	int i;

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

void	match_condition(int cnt_p, int cnt_c, int cnt_e)
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

void	check_components(t_vars *vars, char **map_c)
{
	int i;
	int j;
	int cnt[3];

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

void	make_map(t_vars *vars, char **map_c)
{
	int	i;
	int j;

	vars->map = malloc(sizeof(t_type *) * vars->col);
	i = 0;
	while (i < vars->col)
	{
		vars->map[i] = malloc(sizeof(t_type) * vars->row);
		j = 0;
		while (j < vars->row)
		{
			if (map_c[i][j] == '0')
				vars->map[i][j] = road;
			if (map_c[i][j] == '1')
				vars->map[i][j] = wall;
			if (map_c[i][j] == 'P')
			{
				vars->map[i][j] = hito0;
				vars->player[X] = j;
				vars->player[Y] = i;
			}
			if (map_c[i][j] == 'C')
				vars->map[i][j] = item;
			if (map_c[i][j] == 'E')
				vars->map[i][j] = closed_door;
			j++;
		}
		i++;
	}
	free_map_c(vars, map_c);
}

void	init_vars(t_vars *vars)
{
	vars->framerate = 0;
}

int main(int argc, char **argv)
{
	char	**map_c;
	t_vars	vars;

	// 引数名のエラー処理
	check_arg(argc, argv);
	// マップ読み込み
	map_c = read_file(&vars, argv[1]);
	for (int i = 0; i < vars.col; i++)
		printf("%s", map_c[i]);
	printf("\n");
	// マップエラー処理
	check_map(&vars, map_c);
	// // マップの縦横を測る
	vars.row--;
	// マップを二次元配列に突っ込む
	make_map(&vars, map_c);
	
	init_vars(&vars);
	for (int i = 0; i < vars.col; i++)
	{
		for (int j = 0; j < vars.row; j++)
		{
			printf("%d'", vars.map[i][j]);
		}
		printf("\n");
	}
	// windowを開始
	init_window(&vars);
	// マップに合わせて表示
	display_map(&vars);

	// handle_event(&vars);

	return (0);
}

// int kari (t_vars *vars)
// {
// 	printf("%d\n", vars->kari);
// 	mlx_key_hook(vars->win, key_hook, vars);
// 	mlx_loop_hook(vars->mlx, loop_hook, vars);
// 	mlx_loop(vars->mlx);
// 	// mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;
// 	vars.col = 3;
// 	vars.row = 3;
// 	vars.kari = 200;
// 	init_window(&vars);
// 	for (int i = 0; i < vars.col * 100; i++)
// 	{
// 		for (int j = 0; j < vars.row * 100; j++)
// 		{
// 			mlx_pixel_put(vars.mlx, vars.win, i, j, rgb_to_int(vars.kari, vars.kari, vars.kari));
// 		}
		
// 	}
// 	printf("LINE == %d, FILE == %s :", __LINE__, __FILE__);
// 	printf("%d\n", vars.kari);
// 	kari(&vars);
// 	return (0);
// }


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