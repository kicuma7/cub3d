/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:21:08 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/26 20:03:38 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	clear_all_image(t_img *img, int wid, int hei)
{
	t_point	pos;

	pos.x = 0;
	while (((int)pos.x) < wid)
	{
		pos.y = 0;
		while (((int)pos.y) < hei)
		{
			pixel_put(img, pos, 0x000000);
			pos.y++;
		}
		pos.x++;
	}
}
