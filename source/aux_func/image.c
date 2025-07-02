/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:21:02 by user              #+#    #+#             */
/*   Updated: 2025/05/13 10:02:12 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	draw_line_acording_angle(t_player *player, t_img *img, double angle, int line_size)
{
	t_point	final_line_point;

	final_line_point.x = player->center.x + (cos(angle) * line_size);
	final_line_point.y = player->center.y - (sin(angle) * line_size);
	draw_line(player->center, final_line_point, img, 0xFF0000);
}

void	clear_screen(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)img->pixels_hei)
	{
		j = 0;
		while (j < (int)img->pixels_wid)
		{
			pixel_put(img, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

void	init_image(t_mlx *mlx)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	img->pixels_wid = mlx->map->pixels_wid;
	img->pixels_hei = mlx->map->pixels_hei;
	img->img = mlx_new_image(mlx->con, img->pixels_wid, img->pixels_hei);
	img->img_addr = (int *)mlx_get_data_addr(img->img, &(int){0}, \
					&img->size_line, &(int){0});
	mlx->img = img;
}

void	draw_line(t_point begin, t_point end, t_img *img, int color)
{
	double		pixels;
	t_point	delta;
	t_point	pixel;

	delta.x = end.x - begin.x;
	delta.y = end.y - begin.y;
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	if (pixels == 0)
		return ;
	delta.x /= pixels;
	delta.y /= pixels;
	pixel.x = begin.x;
	pixel.y = begin.y;
	while (pixels > 0)
	{
		pixel_put(img, (int)pixel.x, (int)pixel.y, color);
		pixel.x += delta.x;
		pixel.y += delta.y;
		pixels--;
	}
}

void	pixel_put(t_img *img, double x, double y, int color)
{
	int	i;

	i = x + (y * (img->size_line / 4));
	img->img_addr[i] = color;
}
