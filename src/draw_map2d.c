/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:55:21 by user              #+#    #+#             */
/*   Updated: 2025/05/04 08:31:31 by user             ###   ########.fr       */
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
			if (wid == x || (wid + 1) == (x + PIXELS) || \
				hei == y || (hei + 1) == (y + PIXELS))
				pixel_put(img, wid, hei, 0x00FF00);
			wid++;
		}
		hei++;
	}
}

void	draw_map2d(t_map *map, t_img *img, t_player *player)
{
	int	x;
	int	y;
	static bool	get_pos = true;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '1')
				draw_square(img, x * PIXELS, y * PIXELS);
			else if ((map->map[y][x] == 'N' || map->map[y][x] == 'S' || \
					map->map[y][x] == 'E' || map->map[y][x] == 'W') && get_pos)
			{
				player->cardinal_point = map->map[y][x];
				player->pos_x = PIXELS * x;
				player->pos_y = PIXELS * y;
				get_pos = false;
			}
			x++;
		}
		y++;
	}
	(void)img;
}
