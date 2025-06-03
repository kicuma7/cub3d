/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 23:04:15 by user              #+#    #+#             */
/*   Updated: 2025/06/04 00:24:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	draw_map(t_map *map, t_img *img)
{
	t_dimension	wall_dimension;
	t_point		pos;
	int			i;
	int			j;

	wall_dimension.wid = PIXELS;
	wall_dimension.hei = PIXELS;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
			{
				pos.x = j * PIXELS;
				pos.y = i * PIXELS;
				draw_square(img, wall_dimension, pos, 0x00ff00);
			}
			j++;
		}
		i++;
	}
}
