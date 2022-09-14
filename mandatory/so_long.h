/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:15:28 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/14 15:39:11 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
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
	char	*image[TYPE];
	char	*image_ptr[TYPE];
	int		framerate;
}	t_vars;

#endif