/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:32:03 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/04 10:26:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libs/libft/inc/libft.h"
# include "../libs/mlx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>

# define PIXELS 40
# define ESC 65307

typedef	struct	s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	t_point	point_a;
	t_point	point_b;
	t_point	point_c;
	t_point	center;
	char		cardinal_point;
}				t_player;

typedef struct	s_img
{
	void		*img;
	int			size_line;
	int			*img_addr;
	size_t		pixels_wid;
	size_t		pixels_hei;
}				t_img;

typedef struct	s_map
{
	char		**map;
	size_t		hei;
	size_t		wid;
	size_t		pixels_wid;
	size_t		pixels_hei;
}				t_map;

typedef struct	s_mlx
{
	void		*con;
	void		*win;
	t_map		*map;
	t_img		*img;
	t_player	*player;
}				t_mlx;

int			close_and_free(t_mlx *mlx);
void		init_image(t_mlx *mlx);
void		pixel_put(t_img *img, double x, double y, int color);
void		draw_map2d(t_map *map, t_img *img, t_player *player);
void		draw_player2d(t_mlx *mlx, t_player *player);
t_player	*init_player(t_player *player);
void		draw_line(t_point begin, t_point end, t_img *img, int color);

#endif
