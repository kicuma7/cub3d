/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:55:21 by user              #+#    #+#             */
/*   Updated: 2025/05/09 08:48:45 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	set_cardinal_point_angle(t_player *player, char cardinal_point)
{
	if (cardinal_point == 'N')
		player->dir_angle = PI / 2;
	else if (cardinal_point == 'W')
		player->dir_angle = PI;
	else if (cardinal_point == 'S')
		player->dir_angle = PI + (PI / 2);
	else if (cardinal_point == 'E')
		player->dir_angle = 0;
}

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
				set_cardinal_point_angle(player, map->map[y][x]);
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
