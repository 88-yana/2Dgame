#include "mlx.h"
#include <stdlib.h>
# define KEY_ESC 53

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		player[2];
	int		enemy[2];
	int		is_enemy_existing;
	int		now_sum_item;
	int		sum_item;
	int		steps;
	int		framerate;
}	t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}



int main()
{
    int i;
    int j;
    int width = 1000; //ウィンドウのサイズ
    int height = 1000;
	t_vars vars;
    vars.mlx = mlx_init();//fileopenの時のfd的な？
    vars.win = mlx_new_window(vars.mlx, width, height,"test");
	// mlx_win = mlx_new_window(スクリーン識別子, width, height,"test");
	//座標は左上が原点、矢印はx軸が右、y軸が下向きになる
	//でも与えられる図形の座標は一般的な向きの座標のためあとで座標変換が必要となる
   	i= 0;
	while (i < width)
	{
			j = 0;
			while (j < height)
			{
					mlx_pixel_put(vars.mlx, vars.win, i, j, 127);
					j++;
			}
			i++;
	}
	mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);//無限ループを作り、その間ウィンドウを表示させ続ける
    //最初のうちはcntl+Cで強制終了すればおk
    //クリックした時に終了させるなどのプログラムはゆくゆく書く必要がある
	mlx_destroy_window(vars.mlx, vars.win);
    return (1);
}