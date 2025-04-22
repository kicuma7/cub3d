/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:55:19 by jquicuma          #+#    #+#             */
/*   Updated: 2025/04/22 13:17:43 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	fill_square(t_img *img, int wid, int hei, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < PIXELS / 2)
	{
		j = 0;
		while (j < PIXELS / 2)
		{
			pixel_put(img, wid + i, hei + j, color);
			j++;
		}
		i++;
	}
}

void	put_player_on_screen(int pos_wid, int pos_hei, t_mlx *mlx, t_img *img)
{
	fill_square(img, pos_wid * PIXELS, pos_hei * PIXELS, PLAYER_COLOR);
	mlx_put_image_to_window(mlx->con, mlx->win, img->img, 0, 0);
}
