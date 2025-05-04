/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:27:19 by user              #+#    #+#             */
/*   Updated: 2025/05/04 09:54:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

t_player	*init_player(t_player *player)
{
	player->point_a.x = player->pos_x + (PIXELS / 4);
	player->point_a.y = player->pos_y;
	player->point_b.x = player->pos_x;
	player->point_b.y = player->pos_y + PIXELS;
	player->point_c.x = player->pos_x + (PIXELS / 2);
	player->point_c.y = player->pos_y + PIXELS;
	return (player);
}

void	draw_player2d(t_mlx *mlx, t_player *player)
{
	draw_line(player->point_a, player->point_b, mlx->img, 0xFF0000);
	draw_line(player->point_b, player->point_c, mlx->img, 0xFF0000);
	draw_line(player->point_c, player->point_a, mlx->img, 0xFF0000);
}
