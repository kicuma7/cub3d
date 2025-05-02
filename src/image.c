/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:21:02 by user              #+#    #+#             */
/*   Updated: 2025/05/02 13:15:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	init_image(t_mlx *mlx)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	img->pixels_wid = mlx->map->pixels_wid;
	img->pixels_hei = mlx->map->pixels_hei;
	img->img = mlx_new_image(mlx->con, img->pixels_wid, img->pixels_hei);
	img->img_addr = (int *)mlx_get_data_addr(img->img, &(int){0}, \
					&img->size_line, &(int){0});
	mlx->img = img;
}

void	pixel_put(t_img *img, double x, double y, int color)
{
	int	i;

	i = x + (y * (img->size_line / 4));
	img->img_addr[i] = color;
}
