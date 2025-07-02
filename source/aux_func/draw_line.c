/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:59:06 by jquicuma          #+#    #+#             */
/*   Updated: 2025/07/02 12:49:31 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	draw_line(t_point point_ini, t_point point_fin, t_img *img, int color)
{
	float	steps;
	t_point	distance;
	t_point	increment;
	float	i;

	distance.x = point_fin.x - point_ini.x;
	distance.y = point_fin.y - point_ini.y;
	if ((fabs(distance.x)) > (fabs(distance.y)))
		steps = fabs(distance.x);
	else
		steps = fabs(distance.y);
	increment.x = distance.x / steps;
	increment.y = distance.y / steps;
	i = 0;
	while (i < steps)
	{
		pixel_put(img, point_ini, color);
		point_ini.x += increment.x;
		point_ini.y += increment.y;
		i++;
	}
}
