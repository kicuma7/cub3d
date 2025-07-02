/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:00:06 by jquicuma          #+#    #+#             */
/*   Updated: 2025/07/02 12:13:13 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_floor_and_ceil(t_img *img)
{
	t_point	point;

	point.y = 0;
	while (point.y < (SCREEN_HEI / 2))
	{
		point.x = 0;
		while (point.x < SCREEN_WID)
		{
			pixel_put(img, point, 0x92A1CF);
			point.x++;
		}
		point.y++;
	}
	while (point.y < SCREEN_HEI)
	{
		point.x = 0;
		while (point.x < SCREEN_WID)
		{
			pixel_put(img, point, 0x44402A);
			point.x++;
		}
		point.y++;
	}
}

void	draw_wall(t_hit_info hit_info, int x_column, t_img *img)
{
	t_point	wall_point;
	int		color;
	int		line_height;
	int		draw_start;
	int		draw_end;

	line_height = (int)((SCREEN_HEI * 8)/ hit_info.perp_wall_dist);
	draw_start = -line_height / 2 + SCREEN_HEI / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + SCREEN_HEI / 2;
	if (draw_end >= SCREEN_HEI)
		draw_end = SCREEN_HEI - 1;
	if (hit_info.side == 1)
		color = 0xD8AC00;
	else
		color = 0xFDEE2F;
	wall_point.x = x_column;
	wall_point.y = draw_start;
	while (wall_point.y < draw_end)
	{
		pixel_put(img, wall_point, color);
		wall_point.y++;
	}
}

void	draw_3d_game(t_cub *cub)
{
	clear_all_image(cub->img3d, SCREEN_WID, SCREEN_HEI);
	draw_floor_and_ceil(cub->img3d);
	mlx_put_image_to_window(cub->con, cub->win3d, cub->img3d->img, 0, 0);
}
