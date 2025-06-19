/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:49:29 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/19 17:55:59 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	draw_square(t_img *img, int size, t_point pos, int color)
{
	int		i;
	int		j;
	t_point	pixel_pos;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			pixel_pos.x = pos.x + i;
			pixel_pos.y = pos.y + j;
			pixel_put(img, pixel_pos, color);
			j++;
		}
		i++;
	}
}
