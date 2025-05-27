/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:27:19 by user              #+#    #+#             */
/*   Updated: 2025/05/27 09:49:05 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	draw_player_dir(t_player *player, t_img *img)
{
	t_point	final_line_point;
	int		line_size;

	line_size = 20;
	final_line_point.x = player->center.x + (cos(player->dir_angle) * line_size);
	final_line_point.y = player->center.y - (sin(player->dir_angle) * line_size);
	draw_line(player->center, final_line_point, img, 0xFF00FF);
}

void	mov_player(t_player *player, int keycode)
{
	if (keycode == UP)
	{
		player->center.x += MOV_SPEED * cos(player->dir_angle);
		player->center.y -= MOV_SPEED * sin(player->dir_angle);
	}
	else if (keycode == DOWN)
	{
		player->center.x -= MOV_SPEED * cos(player->dir_angle);
		player->center.y += MOV_SPEED * sin(player->dir_angle);
	}
	else if (keycode == LEFT)
	{
		player->center.x += MOV_SPEED * cos(player->dir_angle + (PI / 2));
		player->center.y -= MOV_SPEED * sin(player->dir_angle + (PI / 2));
	}
	else if (keycode == RIGHT)
	{
		player->center.x -= MOV_SPEED * cos(player->dir_angle + (PI / 2));
		player->center.y += MOV_SPEED * sin(player->dir_angle + (PI / 2));
	}
}

t_player	*init_player(t_player *player)
{
	int	pixels_player;

	pixels_player = PIXELS / 2;
	player->center.x = player->pos_x + (pixels_player / 4);
	player->center.y = player->pos_y + (pixels_player / 2);
	return (player);
}

static void	draw_square(int player_size, double center_x, double center_y, \
						t_img *img)
{
	int	i;
	int	j;
	int	half = player_size / 2;

	i = -half;
	while (i < half)
	{
		j = -half;
		while (j < half)
		{
			pixel_put(img, (int)center_x + j, (int)center_y + i, 0xFF00FF);
			j++;
		}
		i++;
	}
}

void	draw_player2d(t_mlx *mlx, t_player *player)
{
	int	size;

	size = PIXELS / 2;
	draw_square(size, player->center.x, player->center.y, mlx->img);
	draw_player_dir(player, mlx->img);
	draw_fov(mlx, player->dir_angle - (FOV / 2));
}


