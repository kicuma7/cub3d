/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:11:54 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/19 18:42:37 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	pixel_put(t_img *img, t_point position, int color)
{
	int	pos;
	int	x;
	int	y;

	x = (int)position.x;
	y = (int)position.y;
	pos = x + (y * (img->size_line / 4));
	img->img_addr[pos] = color;
}
