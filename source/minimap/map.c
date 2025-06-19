/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:05:45 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/19 18:57:10 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	draw_map(char **map, t_img *img)
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
			if (map[y][x] == '1')
			{
				pos.x = (x * TILE) + 1;
				pos.y = (y * TILE) + 1;
				draw_square(img, TILE - 1, pos, 0x3a6332);
			}
			else
			{
				pos.x = (x * TILE) + 1;
				pos.y = (y * TILE) + 1;
				draw_square(img, TILE - 1, pos, 0x3c3c3c);
			}
			x++;
		}
		y++;
	}
}
