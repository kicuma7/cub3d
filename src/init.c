/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:03:07 by user              #+#    #+#             */
/*   Updated: 2025/06/03 22:40:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"
void	tmp_map(t_map *map, const char *filename);

static void	init_img(t_img *img, t_mlx *mlx)
{
	img->img = mlx_new_image(mlx->con, SCREEN_WID, SCREEN_HEI);
	img->img_addr = (int *)mlx_get_data_addr(img->img, &img->bpp, \
					&img->size_line, &(int){0});
	mlx->img = img;
}

void	init(t_mlx *mlx, t_map *map, t_img *img, char *filename)
{
	tmp_map(map, filename);
	init_img(img, mlx);
	mlx->win = mlx_new_window(mlx->con, SCREEN_WID, SCREEN_HEI, "CUB3D");
	mlx->map = map;
}
