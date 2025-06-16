/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:32:03 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/16 19:23:28 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libs/libft/inc/libft.h"
# include "../libs/mlx/mlx.h"
# include "structs.h"
# include "pre_pocess.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

int		close_and_free(t_mlx *mlx);
void	init(t_mlx *mlx, t_map *map, t_img *img, t_player *player, char *filename);
void	pixel_put(t_img *img, t_point position, int color);
void	draw_square(t_img *img, t_dimension dimension, t_point pos, int color);
void	mov_player_position(t_player *player, int keycode);
void	rotate_player(t_player *player, int keycode);
void	draw_line(t_point point_ini, t_point point_fin, t_img *img, int color);

//MINIMAPA 2D
void	draw_map(t_map *map, t_img *img);
void	clear_all_window(t_img *img);
void	draw_player(t_player *player, t_img *img, char **map);
void	update_frame(t_mlx *mlx);
void	draw_player_direction(t_img *img, t_point player_pos, float dir_angle,\
		char **map);

#endif
