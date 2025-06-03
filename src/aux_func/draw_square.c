/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 23:06:24 by user              #+#    #+#             */
/*   Updated: 2025/06/04 00:09:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	draw_square(t_img *img, t_dimension dimension, t_point pos, int color)
{
	int		i;
	int		j;
	t_point	pixel_pos;

	i = 0;
	while (i < (long)dimension.wid)
	{
		j = 0;
		while (j < (long)dimension.hei)
		{
			pixel_pos.x = pos.x + i;
			pixel_pos.y = pos.y + j;
			pixel_put(img, pixel_pos, color);
			j++;
		}
		i++;
	}
}
