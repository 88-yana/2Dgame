/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:15:28 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/21 10:23:38 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../libft/libft.h"
# include "../../libft/ft_printf/ft_printf.h"
# include "../../gnl/get_next_line.h"
# include "mlx.h"
# include <fcntl.h> //O_RDONLY

# define TYPE 14
# define X 0
# define Y 1
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define ON_DESTROY 17

typedef enum e_num {
	back,
	wall,
	road,
	item,
	closed_door,
	open_door,
	hito0,
	hito1,
	hito2,
	hito3,
	hito4,
	hito5,
	enemy,
}	t_type;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_type	**map;
	int		player[2];
	int		enemy[2];
	int		is_enemy_existing;
	size_t	col;
	size_t	row;
	int		now_sum_item;
	int		sum_item;
	int		steps;
	char	*image_ptr[TYPE];
	int		framerate;
	char	*str;
}	t_vars;

void	check_arg(int argc, char **argv);
void	check_map(t_vars *vars, char **map_c);
void	draw_image(t_vars *vars, t_type type);
void	display_map(t_vars *vars);
void	draw_back_white(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		loop_hook(t_vars *vars);
void	init_vars(t_vars *vars);
void	init_window(t_vars *vars);
void	free_map(t_vars *vars);
void	free_map_c(t_vars *vars, char **map_c);
char	**read_file(t_vars *vars, char *file_name);
void	make_map(t_vars *vars, char **map_c);
int		click_x_hook(int keycode, t_vars *vars);

#endif