/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:32:03 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/04 09:56:15 by user             ###   ########.fr       */
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

typedef	struct	s_cordenate
{
	double	x;
	double	y;
}				t_cordenate;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	t_cordenate	point_a;
	t_cordenate	point_b;
	t_cordenate	point_c;
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
void		draw_line(t_cordenate begin, t_cordenate end, t_img *img, int color);

#endif
