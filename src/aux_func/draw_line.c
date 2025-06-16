/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:15:53 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/16 17:29:45 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	draw_line(t_point point_ini, t_point point_fin, t_img *img)
{
	float	steps;
	t_point	distance;
	t_point	increment;
	float	i;

	distance.x = point_fin.x - point_ini.x;
	distance.y = point_fin.y - point_ini.y;
	if ((ABS(distance.x)) > (ABS(distance.y)))
		steps = ABS(distance.x);
	else
		steps = ABS(distance.y);
	increment.x = distance.x / steps;
	increment.y = distance.y / steps;
	i = 0;
	while (i < steps)
	{
		pixel_put(img, point_ini, 0xFF00FF);
		printf("X: %d, Y: %d\n", (int)point_ini.x, (int)point_ini.y);
		point_ini.x += increment.x;
		point_ini.y += increment.y;
		i++;
	}
}
