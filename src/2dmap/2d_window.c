/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:44:11 by user              #+#    #+#             */
/*   Updated: 2025/06/16 19:22:48 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	clear_all_window(t_img *img)
{
	t_point	position;

	position.x = 0;
	while (position.x < SCREEN_WID)
	{
		position.y = 0;
		while (position.y < SCREEN_HEI)
		{
			pixel_put(img, position, 0x000000);
			position.y += 1;
		}
		position.x += 1;
	}
}

void	update_frame(t_mlx *mlx)
{
	clear_all_window(mlx->img);
	draw_map(mlx->map, mlx->img);
	draw_player(mlx->player, mlx->img, mlx->map->map);
	mlx_put_image_to_window(mlx->con, mlx->win, mlx->img->img, 0, 0);
}
