/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:27:19 by user              #+#    #+#             */
/*   Updated: 2025/05/04 10:41:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

t_player	*init_player(t_player *player)
{
	int	pixels_player;

	pixels_player = PIXELS;
	player->point_a.x = player->pos_x + (pixels_player / 4);
	player->point_a.y = player->pos_y;
	player->point_b.x = player->pos_x;
	player->point_b.y = player->pos_y + pixels_player;
	player->point_c.x = player->pos_x + (pixels_player / 2);
	player->point_c.y = player->pos_y + pixels_player;
	player->center.x = player->point_a.x;
	player->center.y = player->point_a.y + (pixels_player / 2);
	return (player);
}

void	draw_player2d(t_mlx *mlx, t_player *player)
{
	draw_line(player->point_a, player->point_b, mlx->img, 0xFF0000);
	draw_line(player->point_b, player->point_c, mlx->img, 0xFF0000);
	draw_line(player->point_c, player->point_a, mlx->img, 0xFF0000);
}
