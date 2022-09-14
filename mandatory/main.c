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

int rgb_to_int(int r, int g, int b)
{
	int color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

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

void	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 100 * vars->row, 100 * vars->col, "so_long");
}

void	draw_image(t_vars *vars, t_type type)
{
	size_t i;
	size_t j;

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

void	free_map(t_vars *vars)
{
	size_t i;

	i = 0;
	while (i < vars->col)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
}

void	chage_closed_to_open(t_vars *vars)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < vars->col)
	{
		j = 0;
		while (j < vars->row)
		{
			if (vars->map[i][j] == closed_door)
				vars->map[i][j] = open_door;
			j++;
		}
		i++;
	}
}

void	chage_map(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == item)
	{
		vars->now_sum_item++;
		ft_printf("%d, %d", vars->now_sum_item, vars->sum_item);
		if (vars->now_sum_item == vars->sum_item)
			chage_closed_to_open(vars);
	}
	else if (vars->map[y][x] == open_door)
	{
		free_map(vars);
		ft_printf("success, steps : %d\n", vars->steps);
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0) ;
	}
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
		ft_printf("steps : %d\n", vars->steps);
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
	make_image_ptr(vars, road, "image_xpm/lemon.xpm");
	make_image_ptr(vars, item, "image_xpm/cherry.xpm");
	make_image_ptr(vars, closed_door, "image_xpm/closed_door.xpm");
	make_image_ptr(vars, open_door, "image_xpm/door.xpm");
	make_image_ptr(vars, hito0, "image_xpm/hito00.xpm");
	make_image_ptr(vars, hito1, "image_xpm/hito01.xpm");
	make_image_ptr(vars, hito2, "image_xpm/hito02.xpm");
	make_image_ptr(vars, hito3, "image_xpm/hito03.xpm");
	make_image_ptr(vars, hito4, "image_xpm/hito04.xpm");
	make_image_ptr(vars, hito5, "image_xpm/hito05.xpm");
	make_image_ptr(vars, enemy, "image_xpm/enemy.xpm");
}

void	decide_enemy_move(t_vars *vars, int dr);

void	move_enemy(t_vars *vars, int x, int y, int dr)
{
	printf("%d\n", vars->framerate);
	if (vars->map[y][x] != wall && vars->map[y][x] != closed_door && vars->map[y][x] != item && vars->map[y][x] != open_door)
	{
		vars->map[vars->enemy[Y]][vars->enemy[X]] = road;
		vars->enemy[X] = x;
		vars->enemy[Y] = y;
		vars->map[y][x] = enemy;
		if (vars->enemy[X] == vars->player[X] && vars->enemy[Y] == vars->player[Y])
		{
			free_map(vars);
			ft_printf("failure, enemy catched you");
			exit (0);
		}
		return ;
	}
	decide_enemy_move(vars, (dr + 1) % 4);
	return ;
}

void	decide_enemy_move(t_vars *vars, int dr)
{
	int x;
	int y;

	x = vars->enemy[X];
	y = vars->enemy[Y];

	if (dr == 0)
		move_enemy(vars, x, y - 1, dr);
	if (dr == 1)
		move_enemy(vars, x - 1, y, dr);
	if (dr == 2)
		move_enemy(vars, x, y + 1, dr);
	if (dr == 3)
		move_enemy(vars, x + 1, y, dr);
	return ;
}

int	key_hook(int keycode, t_vars *vars)
{
	int x;
	int y;

	x = vars->player[X];
	y = vars->player[Y];
	if (keycode == KEY_W)
	{
		move_player(vars, x, y - 1);
		decide_enemy_move(vars, vars->framerate % 4);
	}
	if (keycode == KEY_A)
	{
		move_player(vars, x - 1, y);
		decide_enemy_move(vars, vars->framerate % 4);
	}
	if (keycode == KEY_S)
	{
		move_player(vars, x, y + 1);
		decide_enemy_move(vars, vars->framerate % 4);
	}
	if (keycode == KEY_D)
	{
		move_player(vars, x + 1, y);
		decide_enemy_move(vars, vars->framerate % 4);
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free_map(vars);
		exit(0);
	}
	return (0);
}

int	loop_hook(t_vars *vars)
{
	t_type	type;

	type = road;
	while (type <= enemy)
	{
		draw_image(vars, type);
		type++;
	}
	type = hito0;
	while (type <= hito5)
	{
		if ((t_type) vars->framerate / 9 + hito0 == type)
			vars->map[vars->player[Y]][vars->player[X]] = type;
		type++;
	}
	if (vars->framerate ==  54)
		vars->framerate = 0;
	vars->framerate++;
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
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop_hook (vars->mlx, loop_hook, vars);
	mlx_loop(vars->mlx);
}

char	**read_file(t_vars *vars, char* file_name)
{
	int fd;
	size_t i;
	size_t sum_nl;
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
	size_t i;

	i = 0;
	while (i < vars->col)
	{
		free(map_c[i]);
		i++;
	}
	free(map_c);
}







void	make_map(t_vars *vars, char **map_c)
{
	size_t	i;
	size_t j;

	vars->map = malloc(sizeof(t_type *) * vars->col);
	i = 0;
	while (i < vars->col)
	{
		vars->map[i] = malloc(sizeof(t_type) * vars->row);
		j = 0;
		while (j < vars->row)
		{
			if (map_c[i][j] == '0')
			{
				vars->map[i][j] = road;
				if (vars->is_enemy_existing == 0)
				{
					vars->enemy[X] = j;
					vars->enemy[Y] = i;
					vars->map[i][j] = enemy;
					vars->is_enemy_existing = 1;
				}
			}
			if (map_c[i][j] == '1')
				vars->map[i][j] = wall;
			if (map_c[i][j] == 'P')
			{
				vars->map[i][j] = hito0;
				vars->player[X] = j;
				vars->player[Y] = i;
			}
			if (map_c[i][j] == 'C')
			{
				vars->map[i][j] = item;
				vars->sum_item++;
			}
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
	vars->row--;
	vars->framerate = 0;
	vars->sum_item = 0;
	vars->now_sum_item = 0;
	vars->steps = 0;
	vars->is_enemy_existing = 0;
}

void	draw_back_white(t_vars *vars)
{
	for (size_t i = 0; i < vars->col * 100; i++)
		for (size_t j = 0; j < vars->row * 100; j++)
			mlx_pixel_put(vars->mlx, vars->win, j, i, rgb_to_int(255, 255, 255));
}

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
