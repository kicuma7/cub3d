/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:59:44 by jquicuma          #+#    #+#             */
/*   Updated: 2025/04/22 11:18:23 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_image(t_img *img, size_t wid, size_t hei, t_mlx *mlx)
{
	img->img = mlx_new_image(mlx->con, wid, hei);
	img->img_addr = (int *)mlx_get_data_addr(img->img, &(int){0}, \
					&img->size_line, &(int){0});
	mlx->img = img;
}
