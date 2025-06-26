/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:00:06 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/26 20:07:43 by jquicuma         ###   ########.fr       */
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
			pixel_put(img, point, 0xF5F5DC);
			point.x++;
		}
		point.y++;
	}
	while (point.y < SCREEN_HEI)
	{
		point.x = 0;
		while (point.x < SCREEN_WID)
		{
			pixel_put(img, point, 0x92A1CF);
			point.x++;
		}
		point.y++;
	}
}

void	draw_3d_game(t_cub *cub)
{
	clear_all_image(cub->img3d, SCREEN_WID, SCREEN_HEI);
	draw_floor_and_ceil(cub->img3d);
	mlx_put_image_to_window(cub->con, cub->win3d, cub->img3d->img, 0, 0);
}
