
#include "mlx.h"
#include <stdio.h>
#define TYPE 6

int rgb_to_int(int r, int g, int b)
{
	int color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

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

void	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 100 * vars->row, 100 * vars->col,"so_long");
}

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
	printf("%d\n", vars.kari);
	kari(&vars);
	return (0);
}