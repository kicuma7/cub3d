/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:55:19 by jquicuma          #+#    #+#             */
/*   Updated: 2025/04/25 12:59:16 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#include <math.h>

static void	draw_pixels_of_player(float increment, float player_hei, \
					float player_wid)
{

}

static void	draw_triangle_player(t_img *img, double pos_x, \
									double pos_y, int color)
{
	float	player_total_hei;
	float	player_total_wid;
	float	player_hei;
	float	player_wid;
	float	increment;

	player_total_wid = PIXELS / 4;
	player_total_hei = PIXELS / 2;
	player_hei = 0;
	increment = (player_total_wid - 1) / (player_total_hei - 1);
	while (player_hei < player_total_hei)
	{
		player_wid = 1 + increment * player_hei;
		int width = roundf(player_wid);
		int start_x = pos_x - width / 2;
		int i = 0;
		while (i < width)
		{
			pixel_put(img, start_x + i, pos_y + player_hei, color);
			i++;
		}
		player_hei++;
	}
}


void	put_player_on_screen(double pos_wid, double pos_hei, t_mlx *mlx, \
					t_img *img)
{
	draw_triangle_player(img, pos_wid * PIXELS, pos_hei * PIXELS, PLAYER_COLOR);
	mlx_put_image_to_window(mlx->con, mlx->win, img->img, 0, 0);
}
