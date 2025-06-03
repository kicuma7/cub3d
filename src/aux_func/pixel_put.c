/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:57:17 by user              #+#    #+#             */
/*   Updated: 2025/06/04 00:06:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

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
