/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:35:02 by jquicuma          #+#    #+#             */
/*   Updated: 2025/04/25 12:58:47 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"

# define ERROR_CODE -1
# define PIXELS 10
# define MAP_COLOR 0x00FF00
# define PLAYER_COLOR 0x0000FF
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ROT_LEFT 97
# define ROT_RIGHT 100
# define ESC 65307
# define MOV 0.1

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>

typedef struct	s_img
{
	int		size_line;
	void	*img;
	int		*img_addr;
}			t_img;

typedef struct	s_mlx
{
	int		map_wid;
	int		map_hei;
	double	player_pos_wid;
	double	player_pos_hei;
	void	*con;
	void	*win;
	char	**map;
	t_img	*img;
}				t_mlx;

int		mlx_destroy_all(t_mlx *mlx);
int		build_map(t_mlx *mlx, char *mapfilename);
void	init_image(t_img *img, size_t wid, size_t hei, t_mlx *mlx);
void	pixel_put(t_img *img, int wid_x, int hei_y, int color);
void	put_map_to_screen(char **map, t_img *img, t_mlx *mlx);
void	put_player_on_screen(int pos_wid, int pos_hei, t_mlx *mlx, t_img *img);
//void	fill_square(t_img *img, int wid, int hei, int color);
void	clear_screen(t_img *img, int screen_wid, int screen_hei);

#endif
