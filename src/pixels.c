/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:59:44 by jquicuma          #+#    #+#             */
/*   Updated: 2025/04/22 11:34:40 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pixel_put(t_img *img, int wid_x, int hei_y, int color)
{
	int	i;

	i = wid_x + (hei_y * (img->size_line / 4));
	img->img_addr[i] = color;
}

void	init_image(t_img *img, size_t wid, size_t hei, t_mlx *mlx)
{
	img->img = mlx_new_image(mlx->con, wid * PIXELS, hei * PIXELS);
	img->img_addr = (int *)mlx_get_data_addr(img->img, &(int){0}, \
					&img->size_line, &(int){0});
	mlx->img = img;
}
