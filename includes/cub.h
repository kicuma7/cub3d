/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:55:53 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/20 14:46:53 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "pre_process.h"
# include "../library/libft/inc/libft.h"
# include "../library/mlx/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <math.h>

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct	s_player
{
	t_point	position;
	float	dir_angle;
}				t_player;

typedef struct		s_img
{
	void			*img;
	int				size_line;
	int				*img_addr;
}					t_img;

typedef	struct		s_map
{
	char			**map;
	unsigned int	wid;
	unsigned int	hei;
}					t_map;

typedef struct	s_cub
{
	void		*con;
	void		*win2d;
	void		*win3d;
	t_img		*img2d;
	t_img		*img3d;
	t_map		*map;
	t_player	*player;
}				t_cub;

void	pixel_put(t_img *img, t_point position, int color);
void	draw_square(t_img *img, int size, t_point pos, int color);
void	init_player(t_player *player, char **map);
int		init(t_map *map, t_cub *cub);
int		close_and_free(t_cub *cub);
void	move_player(t_player *player, int keycode);

/*############ 2D MAP FUNCTIONS #######################*/
void	draw_2d_game(t_cub *cub);


#endif
