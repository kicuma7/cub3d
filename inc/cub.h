/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:32:03 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/04 00:21:23 by user             ###   ########.fr       */
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

int		close_and_free(t_mlx *mlx);
void	init(t_mlx *mlx, t_map *map, t_img *img, char *filename);
void	pixel_put(t_img *img, t_point position, int color);
void	draw_square(t_img *img, t_dimension dimension, t_point pos, int color);

//MINIMAPA 2D
void	draw_map(t_map *map, t_img *img);

#endif
