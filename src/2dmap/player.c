/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 01:03:04 by user              #+#    #+#             */
/*   Updated: 2025/06/16 19:48:59 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void draw_player_direction(t_img *img, t_point player_pos, float dir_angle,\
						char **map)
{
	t_point	increment;
	t_point final_pos;
	int x;
	int y;

	int i = 0;
	increment = player_pos;
	while (1)
	{
		increment.x += 1 * sin(dir_angle);
		increment.y += 1 * -cos(dir_angle);
		x = (int)increment.x / PIXELS;
		y = (int)increment.y / PIXELS;
		(void)map;
		if (map[y][x] == '1')
			break ;
		i++;
	}
	final_pos.x = increment.x;
	final_pos.y = increment.y;
	draw_line(player_pos, final_pos, img, 0xff0000);
}

void	draw_player(t_player *player, t_img *img, char **map)
{
	t_dimension	player_dimension;

	player_dimension.wid = PIXELS / 4;
	player_dimension.hei = PIXELS / 4;
	draw_square(img, player_dimension, player->position, 0xff00ff);
	draw_player_direction(img, player->position, player->dir_angle, map);
}
