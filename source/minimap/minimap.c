/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:05:45 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/19 20:04:09 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	clear_all_image(t_img *img, int wid, int hei)
{
	t_point	pos;

	pos.x = 0;
	while (((int)pos.x) < wid)
	{
		pos.y = 0;
		while (((int)pos.y) < hei)
		{
			pixel_put(img, pos, 0x000000);
			pos.y++;
		}
		pos.x++;
	}
}

static void	draw_map(char **map, t_img *img)
{
	int		x;
	int		y;
	t_point	pos;

	y = 0;
	(void)img;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			pos.x = (x * TILE) + 1;
			pos.y = (y * TILE) + 1;
			if (map[y][x] == '1')
				draw_square(img, TILE - 1, pos, 0x3a6332);
			else
				draw_square(img, TILE - 1, pos, 0x3c3c3c);
			x++;
		}
		y++;
	}
}

static void	draw_player(t_player *player, t_img *img)
{
	draw_square(img, TILE / 4, player->position, 0x000099);
}

void	draw_2d_game(t_cub *cub)
{
	clear_all_image(cub->img2d, cub->map->wid * TILE, cub->map->hei * TILE);
	draw_map(cub->map->map, cub->img2d);
	draw_player(cub->player, cub->img2d);
}
