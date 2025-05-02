/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:55:21 by user              #+#    #+#             */
/*   Updated: 2025/05/02 13:14:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	draw_square(t_img *img, int x, int y)
{
	int	wid;
	int	hei;

	hei = y;
	while (hei < (y + PIXELS))
	{
		wid = x;
		while (wid < (x + PIXELS))
		{
			pixel_put(img, wid, hei, 0x00FF00);
			wid++;
		}
		hei++;
	}
}

void	draw_map2d(t_map *map, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '1')
				draw_square(img, x * PIXELS, y * PIXELS);
			x++;
		}
		y++;
	}
	(void)img;
}
