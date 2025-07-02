/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:05:45 by jquicuma          #+#    #+#             */
/*   Updated: 2025/07/02 12:27:11 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	draw_direction(t_img *img, t_player *player)
{
	int		i;
	t_point	player_direction;
	t_point	increment;

	i = 0;
	player_direction.x = cos(player->dir_angle + (270 * (PI / 180)));
	player_direction.y = sin(player->dir_angle + (270 * (PI / 180)));
	increment.x = player->position.x;
	increment.y = player->position.y;
	while (i < (TILE / 8))
	{
		increment.x += player_direction.x;
		increment.y += player_direction.y;
		i++;
	}
	draw_line(player->position, increment, img, 0x00ff00);
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
	draw_direction(img, player);
}

void	draw_2d_game(t_cub *cub)
{
	clear_all_image(cub->img2d, cub->map->wid * TILE, cub->map->hei * TILE);
	draw_map(cub->map->map, cub->img2d);
	clear_all_image(cub->img3d, SCREEN_WID, SCREEN_HEI);
	draw_player(cub->player, cub->img2d);
	ray_launcher(cub->player, cub->map->map, cub->img2d, cub->img3d);
	mlx_put_image_to_window(cub->con, cub->win3d, cub->img3d->img, 0, 0);
	mlx_put_image_to_window(cub->con, cub->win3d, cub->img2d->img, 0, 0);
}
